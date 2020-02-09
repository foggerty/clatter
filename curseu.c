#include <stdio.h>
#include <stdlib.h>

#include "curseu.h"

#define COLUMN_WIDTH 40

void pad(const char *caption) {
  int i = 0;

  for (;; i++) {
    if (caption[i] == 0) {
      break;
    }
  }

  for (; i < 40; i++) {
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

void print_capability(const char *displayName, const char *value) {
  printf("%s", displayName);
  pad(displayName);
  printf("%s\n", value);
}

void dump_capabilities(void) {
  char buff[40];

  initscr();
  endwin();

  snprintf(buff, 40, "%d / %d", LINES, COLS);
  print_capability("Lines / Columns", buff);

  snprintf(buff, 40, "%s", has_colors() ? "YES" : "NO");
  print_capability("Supports colours", buff);

  print_capability_flag("Terminal can redefine colour:", CAN_CHANGE);
  print_capability_flag("Has META key", HAS_META_KEY);
  print_capability_flag("Has a status line", HAS_STATUS_LINE);

  print_capability_int("Bytes buffered before printing", BUFFER_CAPACITY);
  print_capability_int("Max colours", MAX_COLORS);
}
