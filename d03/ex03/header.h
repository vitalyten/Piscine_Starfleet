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
void insertMonkey(struct s_node **root, struct s_node *monkey);


/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
struct s_node *genMaxHeap(unsigned seed);
void printBinaryTree(struct s_node *t);
struct s_node *randomMonkey(void);
int MIN (int X, int Y);
int MAX (int X, int Y);


/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
