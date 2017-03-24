#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/
typedef struct  s_node {
	int value;
	struct s_node *right;
	struct s_node *left;
}               t_node;


/*--------------------------------
  :) function you must implement
  --------------------------------*/
void	saveTheSequoia(struct s_node **root);


/*--------------------------------
  ?? test function used in main
  --------------------------------*/
struct s_node *genMinHeap(unsigned seed); //generate a min heap
void printBinaryTree(struct s_node * t); //print a binary tree


/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
