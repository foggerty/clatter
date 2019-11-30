#include "themes/themes.h"

#ifndef CLATTER_HEADER
#define CLATTER_HEADER

// Determines what, and how, we will be outputting.
typedef struct OutputInfo {
  // The theme used to render.
  Theme *theme;

  // Name of the file to be rendered.
  char *fname;
} OutputInfo;

const char *Instructions =
  "Clatter - because you've go time to waste!\n\n"
  "Usage: clatter file_name [-l -t theme_name]\n"
  "\t-l : Lists available themes.\n"
  "\t-t : Specifies theme.  Defaults to mother.\n"
  "\t-d : Dump term capabilities as reported by ncurses.\n";

#endif
