#ifndef THEME_HEADER
#define THEME_HEADER

// Theme information, i.e. how to render text.
typedef struct Theme {
  char *name;
  char *description;
} Theme;

// Used for 'stuttered' output by several themes.
typedef struct Stammer {
  int print_delay;    // how long between each character
  int print_length;   // how many chars to print before stuttering
  int stammer_delay;  // how long between each character
  int stammer_length; // how many chars to stutter on
} Stammer;

// Function prototypes
void init_stammer(Stammer *Stammer);

#endif
