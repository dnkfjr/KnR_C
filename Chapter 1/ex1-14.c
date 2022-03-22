#include <stdio.h>

/* print frequency of characters from input */
/* read character from input stream and store in array 
   '0' = 048
   
*/

#define INDEX(A) 48 + A - '0'
#define CHARLIMIT 256

int main(void){

  int charcount[CHARLIMIT] = {0};
  int c, i, j;

  while((c = getchar()) != EOF) {
    charcount[48 + c - '0']++;
  }

  // printout the frequency of characters as bars of '.'
  // display tabs as \t, newline as \n, space as spc, 
  printf("Frequency of character occurence:\n");
  for (i = 0; i < CHARLIMIT ; i++)
    if (charcount[i]){

      switch(i){
        case '\t' : printf(" \\t ");
                    break;
        case '\n' : printf(" \\n ");
                    break;
        case ' ' : printf("spc ");
                    break;
        default   : printf("%3c ", i);
                    break;
      }  
      
      for (j = 0; j < charcount[i]; j++)
        putchar('.');
      putchar('\n');
    }
}