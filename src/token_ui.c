#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"



int main()
{
  printf("Please enter a string.\n> ");
  int c;
  int *arr;

  c = getchar();
  while (c != EOF) {
    putchar(c);
    *arr = c;
    arr++;
    c = getchar();
    if (c == '\n')
      goto done;
  }

 done:
  printf("\n");
  return 0;
}
