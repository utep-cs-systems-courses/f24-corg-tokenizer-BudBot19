#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"


int space_char(char c)

{

  if(c == '\t' || c == ' ' || c == '\n')

    return 1;

  else

    return 0;

}



int non_space_char(char c)

{

  if(c != '\t' & c != ' ' & c != '\n')

    return 1;

  else

    return 0;

}



char *token_start(char *str)
{
  
  while(*str != 0){
    if(non_space_char(*str)){
	return str;
    }
    str++;

  }
  return 0;


}



char *token_terminator(char *token)

{
  int i = 0;
  while(*token != 0){
    if(space_char(*token))
      *token = '\0';
    i++;
    token++;
  }
  token -= i;
  return token;

}



int count_tokens(char *str)
{
  int count = 0;
  while(*str){
    if(space_char(*str))
      count++;
    str++;
  }

  return count;

}



char *copy_str(char *inStr, short len)

{
  char *copy;
  copy = (char *) malloc(len+1);
  int i = 0; 
  while(len > 0){
    copy = inStr;
    len--;
    copy++;
    inStr++;
    i++;
  }
  copy -= i;
  free(copy);
  return copy;

}



char **tokenize(char* str)

{
  char** arr;
  int token_num = count_tokens(str);
  arr = (char **) malloc((token_num + 1) * sizeof(char *));
  short i = 0;
  short arr_count = 0;

  while(token_num){
    if(space_char(*str)){
      *arr = copy_str(str - i, i); 
      arr++;
      arr_count++;
      i = 0;
    }
    i++;
    str++;
    token_num--;
  }
  
  arr -= arr_count;
  return arr;

}



void print_tokens(char **tokens)
{
  while(tokens != NULL){
    while(*tokens != NULL){
      if(non_space_char(**tokens))
	printf("The stored tokens are: \n%s", **tokens);
      *tokens = (*tokens)++;
    }
    tokens++;
    printf("\n");
  }
  
}



void free_tokens(char **tokens)

{
  while(tokens){
    free(*tokens);
    *tokens++;
  }

}
