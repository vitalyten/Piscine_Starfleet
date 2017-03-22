#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/

/*--------------------------------
  :) function you must implement
  --------------------------------*/

// Tank

typedef struct  s_elem {
    int energy;
    struct s_elem *next;
}               t_elem;

typedef struct  s_stack {
    struct s_elem *elem;
    int sum;
}               t_stack;

typedef struct  s_tank {
    struct s_stack **stacks;
    int n;
}               t_tank;

struct s_tank *initTank(void);

void tankPush(struct s_tank *tank, int energy);

int tankPop(struct s_tank *tank);

/*--------------------------------
  ?? test function used in main
  --------------------------------*/


/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
