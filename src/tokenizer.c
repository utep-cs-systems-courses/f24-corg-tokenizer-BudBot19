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


//unsure if this works
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
    if(space_char(*str)) //faulty but works with clean input
      count++;
    str++;
  }

  return count;

}



char *copy_str(char *inStr, short len)
{

  char *copy = (char *) malloc(len + 1);
  for (int i = 0; i < len; i++) {
    copy[i] = inStr[i]; // do [] with pointers to avoid permanent adress changes
  }

  copy[len] = '\0'; //null terminator at the end
  return copy;

}





char **tokenize(char* str)
{
  int token_num = count_tokens(str);
  char **arr = (char **) malloc((token_num + 1) * sizeof(char *));  // +1 for terminator
  int index = 0;
  short i = 0; //token length

  while (*str) {
    if (space_char(*str)) {
      if (i > 0) { //avoids empty string
	arr[index] = copy_str(str - i, i);
	index++;
	i = 0; //resets i so copy_str gets the right length
      }
    } else {
      i++;
    }
    str++;
  }


  // in case there is anything left
  if (i > 0) {
    arr[index] = copy_str(str - i, i);
    index++;
  }



  arr[index] = NULL;  //caps off string with NULL terminator
  return arr;
}



void print_tokens(char **tokens)
{
 printf("The stored tokens are:\n");
 while (*tokens) {
   printf("%s\n", *tokens);
   tokens++;
  }
}



void free_tokens(char **tokens)

{
  while(tokens){
    free(*tokens);
    *tokens++;
  }

}
