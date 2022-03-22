#include <stdio.h>

#define OUT 0
#define IN 1
#define MAX(A,B) (A > B) ? A : B
#define MAXRECORD 26

/* print histogram of the lengths of the words in the input. 
*/

int main(void){

  int c, i, len = 0;
  int wlengths[MAXRECORD] = {0};    //assume maximum word lenght is 22characters
  int state = OUT;
  int maxlen, hist_ub_x, hist_ub_y = 0;

  // while ((c = getchar()) != EOF){
  //   if (c == ' ' || c == '\n' || c == '\t'){
  //     if (state == IN){         // whitespace found after inside word
  //       wlengths[len]++;        // record the length of word in array
  //       maxlen = MAX(maxlen, len);
  //       len = 0;                // reset length to 0
  //     } 
  //     state = OUT;
  //     continue;
  //   }
  //   else if (state == OUT)
  //     state = IN;

  //   ++len;
  // }

  while ((c = getchar()) != EOF){
    if (c == ' ' || c == '\n' || c == '\t'){
      if (len && len < MAXRECORD){    // if space is found after word (len > 0)
        wlengths[len]++;              // record the length of word in array
        maxlen = MAX(maxlen, len);
        len = 0;                      // reset length to 0
      } 
    }
    else
      ++len;
  }

  // print histogram in vertical mode
  int maxcount = 0;                     
  for (i=0; i < maxlen + 1; i++){
    maxcount = MAX(wlengths[i], maxcount);
  }

  printf("The longest word is %d character%s long\n", maxlen, (maxlen > 1) ? "s" : "");
  
  hist_ub_y = (maxcount / 5 + 1) * 5;    // histogram y-axis limit rounded up to next 5
  hist_ub_x = (maxlen / 5 + 1) * 5;    // histogram x-axis limit rounded up to next 5
 
  
  printf("\nHistogram of Word length\n  ^\n");
  for (i=0; i < hist_ub_y + 1; i++){
    printf("%2d|", hist_ub_y - i);
    for (int j = 1; j <= hist_ub_x; j++)
      if (wlengths[j] >= hist_ub_y - i && hist_ub_y > i)
        printf("  X");
      else if (i == hist_ub_y) 
        printf("---");
      else printf("   ");
    printf("\n");
  }
  printf("   ");
  for (i = 1; i <= hist_ub_x; i++)
    printf(" %02d", i);
  printf("   Word length\n");
}