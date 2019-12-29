#include <math.h>
#include <stdlib.h>

#include "theme.h"

void init_stutter(Stutter *stutter) {
  // initial seed determines all other values
  int seed = (rand() % 6) + 1;

  stutter->print_delay = ceil(seed / 2);
  stutter->print_length = seed * 50;
  stutter->stutter_delay = seed * 4;
  stutter->stutter_length = seed * 2;
}
