#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/

struct s_elem {
	char word[100];
	int  occurence;
};

struct s_list {
	struct s_elem **elems;
	int len;
};


/*--------------------------------
  :) function you must implement
  --------------------------------*/

#define MIN_LENGTH 4

char **mostUsedWords(char *book);


/*--------------------------------
  ?? test function used in main
  --------------------------------*/

char *readFile(void);


/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
