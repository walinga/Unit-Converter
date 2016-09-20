/**
 * A simple metric unit converter
 */

#include <stdio.h>
#include <stdlib.h>
#include "conversion.h"

int main(void) {
  float amount;
  char *unit1 = malloc(10 * sizeof(char));
  char *unit2 = malloc(10 * sizeof(char));
  while (1) {
    printf("Enter starting amount and unit:\n");
    int j = scanf(" %f", &amount);
    if (j == EOF) break;
    
    j = scanf(" %s", unit1);
    if (j == EOF) break;
    
    printf("Enter unit to convert to:\n");
    j = scanf(" %s", unit2);
    if (j == EOF) break;

    double res = convert_units(amount, unit1, unit2);

    printf("Result: %g %s\n", res, unit2);
  }
  
  free(unit1);
  free(unit2);
}

