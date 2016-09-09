#include <string.h>
#include <stdio.h>
#include <stdbool.h>

double convert_units(float amount, char *from, char *to) {
  double multiplier;
  double deflator;
  
  bool to_short = strlen(to) == 1;
  bool from_short = strlen(from) == 1;
  char prefixes[5] = {'m', 'c', 'd', 'h', 'k'};
  double values[5] = {1, 10, 100, 100000, 1000000};
  
  for (int i=0; i < 5; ++i) {
    if (prefixes[i] == from[0]) {
      multiplier = values[i];
    }
    if (prefixes[i] == to[0]) {
      deflator = values[i];
    }
  }

  // dam has a weird name so we'll check for it here
  if (from[0] == 'd' && from[1] == 'a') {
    multiplier = 10000;
  } else if (from_short) { // no prefix
    multiplier = 1000;
  }
  
  if (to[0] == 'd' && to[1] == 'a') {
    deflator = 10000;
  } else if (to_short) {
    deflator = 1000;
  }
  
  double converted = (multiplier / deflator) * amount;
  
  if (to[1] == from[1] || to_short || from_short) {
    return converted; 
  } else {
    printf("Cannot convert from %s to %s\n", from, to);
    return 0;
  }
}