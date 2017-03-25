#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/
typedef struct  s_node {
	char		      c;
	unsigned int	isWord:1;
	struct s_node	**child;
}               t_node;

typedef struct  s_trie {
	struct s_node *node;
}               t_trie;


/*--------------------------------
  :) function you must implement
  --------------------------------*/
struct s_trie *createTrie(char **dictionary);
char *understand(char *word, struct s_trie *trie);


/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
extern char *g_dict[];

char *understandAll(char *sentence, struct s_trie *trie);


/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
