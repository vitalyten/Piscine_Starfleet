#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/
typedef struct 	s_node {
	int value;
	struct s_node *right;
	struct s_node *left;
}				t_node;

typedef struct 	s_info {
	int min; //the minimum value in the tree
	int max; //the max value in the tree
	int elements; //nombre d'elements
	int depth; //la profondeur de l'arbre
	int isBST; //1 = TRUE, 0 = FALSE
	int isBalanced; //1 = TRUE, 0 = FALSE
}				t_info;

/*--------------------------------
  :) function you must implement
  --------------------------------*/
struct s_info   getInfo(struct s_node *root);


/*--------------------------------
  ?? test function used in main
  --------------------------------*/
void printBinaryTree(struct s_node * t); //print a binary tree
struct s_node *genRandomBinaryTree(unsigned seed); //gen a random binary tree
void    printTreeInfo(struct s_info info); //print the info from a binary tree

int MIN (int X, int Y);
int MAX (int X, int Y);


/*--------------------------------
  &  your own other stuff
  --------------------------------*/

#endif
