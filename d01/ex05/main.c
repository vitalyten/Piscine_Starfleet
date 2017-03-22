#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	struct s_tank *tank = initTank();

	/*-------------------
	launch your test here
	--------------------*/
	tankPush(tank, 900);
	tankPush(tank, 900);
	tankPush(tank, 900);
	tankPush(tank, 900);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 900);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPush(tank, 100);
	tankPush(tank, 900);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 900);
	tankPush(tank, 900);
	tankPush(tank, 100);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);
	tankPop(tank);


	return (0);
}



// Function used for the test
// Don't go further :)
