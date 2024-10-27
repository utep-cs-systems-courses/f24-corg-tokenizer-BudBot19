#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"


int main()
{
 start:
  printf("Please enter a string.\n> ");
  char c;
  char *str;
  char **tokens;
  str = (char *)malloc(sizeof(char *) * 100);
  
  c = getchar();
  while (c != EOF) {
    putchar(c);
    *str = c;
    str++;
    if(c == '\n')
      goto test;
    c = getchar();
  }

 test:
  printf("\n");
  printf("What would you like to do?\n");
  printf("1 = tokenizer test, 2 = history, 3 = quit, 4 = newstring\n");
 spaceskip:   //Allow the program to skip next line chars
  c = getchar();
  switch (c) {


  case '1':
    printf("testing tokenizer...\n"); 
    tokens = (char **)malloc(count_tokens(str));
    printf("number of tokens: %d", count_tokens(str));
    tokens = tokenize(str);
    print_tokens(tokens);
    goto test;
    
  case '2':
    printf("pulling history...\n");
    goto test;
    
  case '3':
    printf("quiting program...\n");
    goto end;

  case '4':
    goto start;
    
  case '\n':
    goto spaceskip;
    
  default:
    printf("Invalid Input");
    goto test;
  }

 end:
  free(str);
  free(tokens);
  return 0;
}
