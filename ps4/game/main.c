#include<stdio.h>
#include "ballsortpuzzle.h"


int main()
{
	char field[4][6] = {
	{'@', '*', ' ', ' ', '+', '+'},
	{'*', '+', ' ', ' ', '*', '+'},
	{'@', '^', ' ', ' ', '^', '@'},
	{'^', '^', ' ', ' ', '@', '*'}
};

	generator(4,6,field);
	return 0;
}