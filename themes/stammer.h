#ifndef STAMMER_HEADER
#define STAMMER_HEADER

// When to print 'normally' and when to go slowly
typedef struct Stammer {
  int print_delay;    // how long between each character
  int print_length;   // how many chars to print before stammering
  int stammer_delay;  // how long between each character
  int stammer_length; // how many chars to stutter on
} Stammer;

void stammer_init();
void stammer_char(const char c);
void stammer_space();
void stammer_eol();
void stammer_nl();

#endif
