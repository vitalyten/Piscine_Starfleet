#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/
typedef struct  s_max {   // just a container for the max sliding window array and its length
	int *max;
	int length;
}               t_max;

/*--------------------------------
  :) function you must implement
  --------------------------------*/

// DEQUE

typedef struct  s_dequeNode {
	int value;
	struct s_dequeNode *next;
	struct s_dequeNode *prev;
}               t_dequeNode;

typedef struct  s_deque {
	struct s_dequeNode *first;
	struct s_dequeNode *last;
}               t_deque;

struct s_deque *dequeInit(void);
void pushFront(struct s_deque *deque, int value);
void pushBack(struct s_deque *deque, int value);
int popFront(struct s_deque *deque);
int popBack(struct s_deque *deque);

// MAX SLIDING WINDOW

struct s_max *maxSlidingWindow(int *arr, int n, int k);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/


/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
