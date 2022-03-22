#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from []);

int main(void){
  int len;      // current line length
  int max;      // max length seen so far
  char line[MAXLINE] = {};
  char longest[MAXLINE] = {};
  int c;
  int linenum = 0;

  max = 0;

  while ((len = getline(line, MAXLINE)) > 0){
    linenum++;

    // if line length is more than array limit MAXLINE continue incrementing line length until newline is read
    if (len == MAXLINE - 1 && line[len-1] != '\n'){
      while((c=getchar()) != EOF && c != '\n'){
        len++;
      }
      len++;  // add one for newline character
    }
    
    if (len > max) {
      max = len;
      copy (longest, line);
    }
    printf("Line %d read with %d chars.\n", linenum, len);
  }

  if (max > 0){
    printf("\nLongest line read has %d chars.\n", max);
    if (max > MAXLINE - 1)
      printf("Only the first %d characters are read: \n", MAXLINE - 1);
    
    printf("%s\n\n", longest);
  }

  return 0;
}

int getline(char s[], int lim){
  int c, i;

  // loop to read input character
  // loop termination: first check that limit of array is not exceeded
  // for loop will fill up array from index 0 to at most index lim - 2. 
  // index lim - 1 will be filled up with '\0'

  for (i=0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i){
    s[i] = c;
  }

  if (c == '\n') {          // if last character read in for loop is \n
    s[i] = c;               // insert newline into array
    ++i;
  }
  s[i] = '\0';              // end the string with '\0'
  
  return i; 
}

void copy(char to[], char from[]){
  int i = 0;
  while((to[i] = from[i]) != '\0')
    ++i;
}