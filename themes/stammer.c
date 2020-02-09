#include "stammer.h"
#include "theme.h"
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>

Stammer stammer;
int chars_remaining;
int printing;

void stammer_init() {
  // initial seed determines all other values
  int seed = (rand() % 6) + 1;

  stammer.print_delay = seed;
  stammer.print_length = seed * 50;

  stammer.stammer_delay = seed * 6;
  stammer.stammer_length = seed * 2;

  chars_remaining = stammer.print_length;
  printing = 1;
}

void stammer_char(const char c) {
  addch(c);
  refresh();

  chars_remaining--;

  if (chars_remaining <= 0) {
    // time for new stammer values?
    if (!printing) {
      stammer_init(&stammer);
    }

    printing = printing ^ 1;
    chars_remaining = printing ? stammer.print_length : stammer.stammer_length;
  }

  usleep(1000 * (printing ? stammer.print_delay : stammer.stammer_delay));
}

void stammer_space() {
  addch(' ');
  refresh();
}

void stammer_eol() {
  // nothing special for EOL
}

void stammer_nl() {
  addch('\n');
  refresh();
}
