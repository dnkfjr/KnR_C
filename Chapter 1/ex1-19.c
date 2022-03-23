#include <stdio.h>
#define MAXCHAR 1000

// print input lines one at at time in reverse

int getline(char line[], int maxchar);
void reverse(char line[], int strlen);

int main(void){

  int len;
  char line[MAXCHAR] = {};

  while ((len = getline(line, MAXCHAR)) > 0){
    if (len == 1)
      continue;
    else {
      reverse (line, len - 1);
      printf("%s", line);
    }
  }
  return 0;
}

int getline(char s[], int lim){

  int i, c;

  for(i=0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++){
    s[i] = c;
  }
  
  if (c == '\n'){
    s[i++] = c;
  }
  
  s[i] = '\0';  

  return i;
}

void reverse (char s[], int strlen){

  int c, i;
  if (strlen > 1)
    for (i = 0; i < strlen / 2; i++){
      c = s[i] ;
      s[i] = s[strlen - i - 1];
      s[strlen - i - 1] = c;
    }

}