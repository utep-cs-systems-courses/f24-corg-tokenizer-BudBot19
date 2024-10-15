#include <stdio.h>
#include "tokenizer.h"


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



char *token_start(char *str)
{
  char *startp;
  char start;
  while(*str){
    if(non_space_char(*str)){
	start = *str;
	startp = &start;
	return startp;
    }
    *str++;

  }
  return 0;


}



char *token_terminator(char *token)

{
  char *terminator;
  
  terminator = (++*token);
  *terminator = 0;
  return terminator;

}



int count_tokens(char *str)
{
  int count = 0;
  while(*str){
    if(space_char(*str))
      count++;
  }

  return count--;

}



char *copy_str(char *inStr, short len)

{
  char *copy;
  while(len < 0){
    *copy = *inStr;
    len--;
    ++*copy;
    ++*inStr;
  }

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
