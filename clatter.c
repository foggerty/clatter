#include <getopt.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "clatter.h"
#include "curseu.h"
#include "themes/theme.h"

// function prototypes
void list_themes();
void print_instructions();
void set_theme(const char *themeName, OutputInfo *output);
void test_input(OutputInfo *output);

// theme that we'll be using for display
Theme *current_theme;

// do this annoying calculation once...
int num_themes = (sizeof(themes) / sizeof(themes[0]));

void parse_args(int argc, char *argv[], OutputInfo *output) {
  char option;

  while ((option = getopt(argc, argv, "ldt:")) != -1) {
    switch (option) {
    case 'l':
      list_themes();
      exit(EXIT_SUCCESS);
      break;
    case 'd':
      dump_capabilities();
      exit(EXIT_SUCCESS);
    case 't':
      set_theme(optarg, output);
      break;
    case ':':
    case '?':
      print_instructions();
      exit(EXIT_SUCCESS);
      break;
    }
  }

  if (optind < argc) {
    output->fname = argv[optind];
  } else {
    print_instructions();
    exit(EXIT_SUCCESS);
  }
}

void test_input(OutputInfo *output) {
  if (access(output->fname, F_OK | R_OK) == -1) {
    printf("Either %s doesn't exist, or you do not have read access to it.\n",
           output->fname);
    exit(EXIT_FAILURE);
  }
}

void print_instructions() { printf("%s", Instructions); }

void list_themes() {
  printf("Available themes:\n");

  for (int i = 0; i < num_themes; i++) {
    printf("\t%s - %s\n", themes[i].name, themes[i].description);
  }
}

void set_theme(const char *theme_name, OutputInfo *output) {
  for (int i = 0; i < num_themes; i++) {
    if (strcasecmp(theme_name, themes[i].name) == 0) {
      output->theme = &themes[i];
      return;
    }
  }

  printf("Cannot find theme.  Use 'clatter -l' to list available themes.\n");

  exit(EXIT_SUCCESS);
}

void clatter(OutputInfo *output) {
  FILE *f;
  char *buff = NULL;  // getline will malloc for us
  size_t buffer_size; // size of buffer allocated by getline
  ssize_t bytes_read; // excluding \0 char
  Theme *theme;

  f = fopen(output->fname, "r");

  if (f == NULL) {
    printf("Error when attempting to open %s", output->fname);
    exit(EXIT_FAILURE);
  }

  theme = output->theme;
  theme->init();

  while ((bytes_read = getline(&buff, &buffer_size, f)) != -1) {
    for (int i = 0; i < bytes_read; i++) {
      switch (buff[i]) {
      case ' ':
        theme->rspace();
        break;
      case '\n':
        theme->eol();
        theme->nl();
        break;
      default:
        theme->rchar(buff[i]);
        break;
      }
    }
  }

  free(buff);

  if (ferror(f)) {
    printf("Something exploded, look up how to extract information from ferror "
           "so we can display something useful to the user.");
    exit(EXIT_FAILURE);
  }
}

int main(int argc, char *argv[]) {
  struct OutputInfo output;

  // setup
  parse_args(argc, argv, &output);
  test_input(&output); // this could be less confusingly named :-)
  srand(time(0));
  output.theme = &themes[0]; // set the default theme
  initscr();                 // initialise ncurses
  scrollok(stdscr, TRUE);    // allow ncurses to scroll terminal

  // output
  clatter(&output); // print contents

  // tidy up
  printw("\nPress any key...\n");
  getch();
  endwin(); // ncurses clean-up

  return EXIT_SUCCESS;
}
