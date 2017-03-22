#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/
typedef struct s_node {
	char          *word;
	struct s_node *next;
}               t_node;

/*--------------------------------
  :) function you must implement
  --------------------------------*/
void printReverse(t_node *lst);

/*--------------------------------
  ?? test function used in main
  --------------------------------*/
t_node *createList(char **words, int n);

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
