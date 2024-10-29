#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"


int main()
{
  List *history = init_history();

 start:
  printf("Please enter a string.\n> ");
  char c;
  char *str;
  char **tokens;
  int i = 0; //keep track of adress changes
  str = (char *)malloc(sizeof(char *) * 50);
  
  c = getchar();
  if(c == '\n')
    goto start;
  
  while (c != EOF) {
    putchar(c);
    *str = c;
    str++;
    i++;
    if(c == '\n'){
      str -= i; //moves address to og location
      add_history(history, str); //updates history
      goto test;
    }
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
    tokens = (char **)malloc(100);
    printf("number of tokens: %d\n", count_tokens(str));
    tokens = tokenize(str);
    print_tokens(tokens);
    goto test;
    
  case '2':
    c = getchar();
    printf("Enter (p) to print history or (!) followed by an id number\n");
    c = getchar();
    if(c == 'p')
      print_history(history);
    else if (c == '!'){
      c = getchar();
      scanf(&c, "%d", &i);
      printf("Based on the id: \n%s", get_history(history, i));
    }
    else
      printf("Invalid Input\n");
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
  free_tokens(tokens);
  free_history(history);
  return 0;
}
