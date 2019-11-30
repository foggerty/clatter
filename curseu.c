#include <stdlib.h>
#include <stdio.h>

#include "curseu.h"

#define COLUMN_WIDTH 40

// ToDo - look into function pointers so can reduce repeated code.

void pad(const char *caption) {
  int w = 0;

  for (;; w++) {
    if (caption[w] == 0) {
      break;
    }
  }

  w = COLUMN_WIDTH - w;

  for (; w > 0; w--) {
    putchar(' ');
  }
}

void print_capability_flag(const char *displayName, const char *key) {
  printf("%s", displayName);

  pad(displayName);

  printf("%s\n", tigetflag(key) ? "YES" : "NO");
}

void print_capability_int(const char *displayName, const char *key) {
  printf("%s", displayName);

  pad(displayName);

  printf("%d\n", tigetnum(key));
}

void dump_capabilities(void) {
  const char *lines_columns = "Lines / Columns";
  const char *supports_colors = "Supports colors";

  initscr();
  endwin();

  print_capability_int("Virtual terminal number", VIRTUAL_TERMINAL);

  printf(lines_columns);
  pad(lines_columns);
  printf("%d / %d\n", LINES, COLS);

  printf(supports_colors);
  pad(supports_colors);
  printf("%s\n", has_colors() ? "YES" : "NO" );

  print_capability_flag("Terminal can redefine colour:", CAN_CHANGE);
  print_capability_flag("Has META key", HAS_META_KEY);
  print_capability_flag("Has a status line", HAS_STATUS_LINE);

  print_capability_int("Bytes buffered before printing", BUFFER_CAPACITY);
  print_capability_int("Number of mouse buttons", BUTTONS);
  print_capability_int("Max colours", MAX_COLORS);
}
