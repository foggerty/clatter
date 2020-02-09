#include "mother.c"
#include "stammer.h"
#include "theme.h"

#ifndef THEMES_HEADER
#define THEMES_HEADER

// Bring all themes together into a single collection.
struct Theme themes[] = {
    {.name = (char *)"Stammer",
     .description = (char *)"This is the future of console rendering!",
     .rchar = stammer_char,
     .rspace = stammer_space,
     .eol = stammer_eol,
     .nl = stammer_nl,
     .init = stammer_init}};

#endif
