#include <stdio.h>

/* count blanks, tabs and newlines */

int main (void){

  int c, nb, nt, nn;

  for (nb = nt = nn = 0; (c=getchar())!=EOF; ){
    if (c==' ')
      ++nb;
    else if (c == '\t')
      ++nt;
    else if (c == '\n')
      ++nn;
  }

  printf("Number of blanks: %d\n", nb);
  printf("Number of tabs: %d\n", nt);
  printf("Number of newlines: %d\n", nn);

}