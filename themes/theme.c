#include "theme.h"
#include <math.h>
#include <stdlib.h>

void init_stammer(Stammer *stammer) {
  // initial seed determines all other values
  int seed = (rand() % 6) + 1;

  stammer->print_delay = seed;
  stammer->print_length = seed * 50;

  stammer->stammer_delay = seed * 6;
  stammer->stammer_length = seed * 6;
}
