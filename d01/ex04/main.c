#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

struct s_queue *queueInit(void);

char *dequeue(struct s_queue *queue);

void enqueue(struct s_queue *queue, char *message);

char *peek(struct s_queue *queue);

int isEmpty(struct s_queue *queue);

int main(void)
{

	/*-------------------
	launch your test here
	--------------------*/
	t_queue *queue;

	queue = queueInit();
	printf("isempty = %d\n", isEmpty(queue));
	enqueue(queue, "one");
	enqueue(queue, "two");
	enqueue(queue, "three");
	enqueue(queue, "four");
	enqueue(queue, "five");
	printf("isempty = %d\n", isEmpty(queue));
	printf("peek = %s\n", peek(queue));
	printf("dequeue = %s\n", dequeue(queue));
	printf("dequeue = %s\n", dequeue(queue));
	printf("dequeue = %s\n", dequeue(queue));
	printf("dequeue = %s\n", dequeue(queue));
	printf("dequeue = %s\n", dequeue(queue));
	printf("isempty = %d\n", isEmpty(queue));

	return (0);
}



// Function used for the test
// Don't go further :)

