#include <stdio.h>
#include "tokenizer.h"
#include "history.h"



int main()
{
  printf("Please enter a string.\n> ");
  int c;

  c = getchar();
  while (c != EOF) {
    putchar(c);
    c = getchar();
    if (c == '\n')
      goto done;
  }

 done:
  printf("\n");
  return 0;
}

int space_char(char c)
{
  if(c == '\t' || c == ' ')
    return 1;
  else
    return 0;
}

int non_space_char(char c)
{
  if(c != '\t' & c != ' ')
    return 1;
  else
    return 0;
}

char *token_start(char *str);
{
  
}

char *token_terminator(char *token)
{

}

int count_tokens(char *str)
{

}

char *copy_str(char *inStr, short len)
{

}

char **tokenize(char* str)
{

}

void print_tokens(char **tokens)
{

}

void free_tokens(char **tokens)
{

}
