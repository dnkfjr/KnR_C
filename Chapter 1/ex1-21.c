#include <stdio.h>
#define MAXCHAR 1000
#define TABS 8

// detab replaces any tabs with just spaces
// entab replaces spaces with tabs and spaces

int getline(char line[], int maxchar);
int detab(char source[], int strlen, char dest[]);
int entab(char source[], int strlen, char dest[]);

int main(void){

  int len;
  char line[MAXCHAR] = {};
  char entabbed[MAXCHAR] = {};
  char detabbed[MAXCHAR] = {};

  while ((len = getline(line, MAXCHAR)) > 0){
    len = detab (line, len, detabbed);
    len = entab (detabbed, len, entabbed);
    // printf("%s", line);
    printf("%s", entabbed);
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

int entab(char s[], int strlen, char d[]){

  int i, j, k, c;
  int p;
  int spacecount = 0;
  int tabstop;
  // printf("strlen = %d\n", strlen);
  for (i=0, j=0; i < strlen && s[i] != '\n'; i++, j++){
    if (s[i] == ' ')
      if (p == ' ')
        spacecount++;
      else
        spacecount = 1;
    else
      if (p == ' ' && spacecount > 1){
        // printf("at j = %d, i = %d, do space to tabs conversion for %d spaces\n", j, i, spacecount);

        // move j back by spacecount
        j-=spacecount;

        // first handle/check the nearest tab stop
        tabstop = TABS - (i - spacecount) % TABS;
        if (spacecount >= tabstop){
          // printf("d[%d] = '\\t\n", j);
          d[j++] = '\t';
          spacecount -= tabstop;
        }

        // add tab until spacecount is less than TABS
        while (spacecount >= TABS){
          // printf("d[%d] = '\\t\n", j);
          d[j++] = '\t';
          spacecount -= TABS;
        }
        
        // any remaining spacecount will be just blank space
        while (spacecount--){
          // printf("d[%d] = 'spc\n", j);
          d[j++] = ' ';
        }
      }
    d[j] = s[i];
    // printf("d[%d] = %c\n", j, d[j]);
    p = d[j];
  }
  // printf("number of spaces = %d\n", spacecount);

  d[j++] = '\n';
  d[j] = '\0';

  return j;
}

int detab(char s[], int strlen, char d[]){

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

  return j;
}