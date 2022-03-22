#include <stdio.h>

/* skip blanks and print only single blank */

int main(void){

  int c, p;

  for (; (c=getchar())!= EOF;) {
    // if (c ==' ') {        /* if there is a space print it and loop to skip remaining spaces if found */
    //   putchar(c);         
    //   while ((c=getchar()) == ' ')
    //     ;
    // }
    // if (c != EOF) 
    //   putchar(c);
    // else  
    //   return 0;

    /* While the above works, there are repeated commands for getchar and putchar, and repeated
       checks for EOF.
    
    The following steps are cleaner by using continue to skip to next loop */
    if (c == ' ' && p == ' '){    // use p to track previous character
      continue;                   // continue the loop
    }

    putchar(c);
    p = c;
  }

  return 0;
}