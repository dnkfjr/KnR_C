#include <stdio.h>

#define LOWER 0       // lower limit of table
#define UPPER 300     // upper limit of table
#define STEP 20       // step size

double ftoc(int degC);

int main(void){

  int fahr;
  printf("Fahrenheit - Celcius Table\n");
  printf("  F   degC\n");
  for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
    printf("%3d %6.1f\n", fahr, ftoc(fahr)); 
}

double ftoc (int degF){

  return 5.0/9 * (degF - 32);
}