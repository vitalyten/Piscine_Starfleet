#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/

typedef struct  s_node {
	char	*word;
	struct s_node *next;
}               t_node;

/*--------------------------------
  :) function you must implement
  --------------------------------*/

//STACK

typedef struct  s_item {
  char          *word;
  struct s_item *next;
}               t_item;

typedef struct  s_stack {
	struct s_item *item;
}               t_stack;

struct s_stack *stackInit(void);

void *pop(struct s_stack *stack);

void push(struct s_stack *stack, char *word);

//OTHER

void printReverse(struct s_node *lst);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
struct s_node *createList(char **words, int n);

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
