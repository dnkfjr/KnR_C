#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

/* print word one word per line */
/* ignore trailing spaces */
/* use state to track whether state is inside or outside a word */

int main (void) {

  int c, state; 

  state = OUT;
  
  while((c = getchar())!= EOF) {
    
    if (c == '\n' || c == ' ' || c == '\t') {
      if (state == IN) {
        putchar('\n');            // add new line if space or white space is detected after a word
      }
      state = OUT;                // re-set state to OUT 
      continue;                   // next loop
    }
    else if (state == OUT){
      state = IN;                 // set State to IN if not in whitespace
    }
    putchar(c);
  }
}