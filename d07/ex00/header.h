#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/
typedef struct  s_art {
	char *name;
	int price;
}               t_art;

/*--------------------------------
  :) function you must implement
  --------------------------------*/
void heapSort(struct s_art **masterpiece, int n);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
struct s_art **getArts(void);

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
