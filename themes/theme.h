#ifndef THEME_HEADER
#define THEME_HEADER

// Function pointers used to call out to each theme when they need to
// render something.

typedef void (*rndr_char)(const char); // render a single character
typedef void (*new_line)();            // a new line needs to be rendered
typedef void (*eol_reached)();         // a EOL has been reached
typedef void (*rndr_space)();          // render a single space
typedef void (*init_theme)();          // initilise the theme

typedef struct Theme {
  char *name;
  char *description;
  init_theme init;
  rndr_char rchar;
  rndr_space rspace;
  eol_reached eol;
  new_line nl;
} Theme;

#endif
