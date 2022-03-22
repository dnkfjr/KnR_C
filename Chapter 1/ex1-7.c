#include <stdio.h>

/* Print value of EOF*/

int main(void){

  int c;

  while((c = getchar()) != EOF)
    ;           // skip to EOF end of file

  printf("Value of EOF is %d.\n", EOF);
}