#ifndef THEME_HEADER
#define THEME_HEADER


// Theme information, i.e. how to render text.
typedef struct Theme {
  char *name;
  char *description;
} Theme;


// Used for 'stuttered' output by several themes.
typedef struct Stutter {
  int print_delay;    // how long between each character
  int print_length;   // how many chars to print before stuttering
  int stutter_delay;  // how long between each character
  int stutter_length; // how many chars to stutter on
} Stutter;


// Function prototypes
void init_stutter(Stutter *stutter);

#endif
