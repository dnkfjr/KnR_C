#include <stdio.h>

/* count blanks, tabs and newlines */

int main (void){

  int c;

  for (; (c=getchar())!=EOF; ){
    switch(c){
      case '\t': 
          putchar('\\');
          putchar('t');
          break;
      case '\b':
          putchar('\\');
          putchar('b');
          break;
      case '\\':
          putchar('\\');
          putchar('\\');
          break;
      default: 
          putchar(c);
          break;
    }
  }

}