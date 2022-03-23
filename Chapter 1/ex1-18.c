#include <stdio.h>
#define MAXCHAR 1000

// program ignores trailing tabs and spaces
// input lines that are empty (only newline character) are ignored
// - EOF will return 0 to main function
// - blank line will return 1 to main function (one newline character)

int getline(char line[], int maxchar);

int main(void){

  int len;
  char line[MAXCHAR] = {};

  while ((len = getline(line, MAXCHAR)) > 0)
    if (len == 1)   // newline character only, i.e. blank
      continue;
    else
      printf("%s", line);
  return 0;
}

int getline(char s[], int lim){

  int i, c;

  for(i=0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++){
    s[i] = c;
  }
  
  // printf("index i is %d after for loop\n", i);

  // check if previous array item is space or tabs;
  for(; s[i-1] == '\t'|| s[i-1] == ' '; i--)
    ;

  if (c == '\n'){
    // printf("insert \\n on index %d\n", i);
    s[i++] = c;
  }
  
  // printf("insert \\0 on index %d\n", i);
  s[i] = '\0';  

  // printf("return %d to main\n", i);
  return i;
}