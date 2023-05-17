#include<stdio.h>
#include "ballsortpuzzle.h"


int main()
{
	char field[4][6] = {
	{'@', '*', ' ', ' ', ' ', '^'},
	{'@', '*', '+', ' ', '+', '^'},
	{'@', '*', ' ', ' ', '+', '^'},
	{'@', '*', ' ', ' ', '+', '^'}
};
	game_field(4,6,field);
	generator(4,6,field);
	down_possible(4,6,field,3,5);
	printf("%d\n",check(4,6,field));
	return 0;
}