#include <stdio.h>
#define MAXCHAR 1000
#define TABS 8

// replace tabs with spaces

int getline(char line[], int maxchar);
void detab(char source[], int strlen, char dest[]);

int main(void){

  int len;
  char line[MAXCHAR] = {};
  char detabbed[MAXCHAR] = {};

  while ((len = getline(line, MAXCHAR)) > 0){
    if (len == 1)
      continue;
    else {
      detab (line, len, detabbed);
      printf("%s", detabbed);
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

void detab(char s[], int strlen, char d[]){

  int i, j, c;
  int step;
  int tabspace;

  for (i=0, j=0; (j < MAXCHAR - 1) && s[i] != '\n'; i++, j++)
    if (s[i] == '\t'){
      tabspace = TABS - j % TABS;
      for (step = 0; step < tabspace; step++){
        d[j++] = ' ';
      }
      --j;
      // printf("after tabs j = %d\n", j);
    }
    else{
      d[j] = s[i];
    }
  d[j++] = '\n';
  d[j] = '\0';
}