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
struct s_node *createBST(int *arr, int n);


/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
void printBinaryTree(struct s_node * t); //print a binary tree


/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
