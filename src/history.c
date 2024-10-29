#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

/* Initialize the linked list to keep the history. */

List* init_history()
{
  List *start; //pointer to the beggining of list
  start = (List *)malloc(sizeof(List));
  start -> root = NULL;
  return start;
}



/* Add a history item to the end of the list.

   List* list - the linked list

   char* str - the string to store

*/

void add_history(List *list, char *str)
{
  Item *new = (Item *)malloc(sizeof(Item));
  Item *current = list -> root;
  int i = 0; //tracks id

  while(current != NULL){
    current = current -> next;
    i++;
  }

  new -> id = i;

  i=0;
  while(str[i] != '\n'){ //calculates length
    i++;
  }

  new -> str = copy_str(str, i+1);
  new -> next = NULL;
  current = new;
}



/* Retrieve the string stored in the node where Item->id == id.

   List* list - the linked list

   int id - the id of the Item to find */

char *get_history(List *list, int id)
{
  Item *current = list -> root;

  while(current !=NULL){
    if(current -> id == id){
      if(current -> str != NULL){
	return current -> str;
      } else {
	printf("There is no string at id\n");
      }
    }
    current = current -> next;
  }
  printf("Could not find given id\n");
  return 0;
}



/*Print the entire contents of the list. */

void print_history(List *list)
{
  Item *current = list -> root;

  while(current != NULL){
    printf("ID: %d", current -> id, " String: %s\n", current -> str);
    current = current -> next;
  }
}



/*Free the history list and the strings it references. */

void free_history(List *list)
{
  Item *current = list -> root;
  
  while(current != NULL){
    free(current -> str);
    free(current);
    current = current -> next;
  }

  free(list);
}
