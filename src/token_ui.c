#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"


int main()
{
  printf("Please enter a string.\n> ");
  char c;
  char *arr;
  arr = (char *) malloc(100);
  
  c = getchar();
  while (c != EOF) {
    putchar(c);
    *arr = c;
    arr++;
    if (c == '\n')
      goto test;
    c = getchar();
  }

 test:
  printf("\n");
  printf("What would you like to do?\n");
  c = getchar();
  switch (c) {

  case '1':
    printf("testing tokenizer...\n");
    goto test;

  case '2':
    printf("printing tokens...\n");
    goto test;
    
  case '3':
    printf("pulling history...\n");
    goto test;
    
  case '4':
    printf("quiting program...\n");
    goto end;
    
  default:
    printf("Invalid Input");
    goto test;
  }

 end:
  return 0;
}
