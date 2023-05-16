#include <stdio.h>
#include <stdlib.h> 
#include "ballsortpuzzle.h"

void generator(const int rows, const int columns, char field[rows][columns])
{	
	int j = 1;
	char space = ' ';

	for(int h = 0; h < rows; h++)
	{
		printf(" %d |",j);

		for(int i = 0 ; i < columns; i++)
		{
			printf(" %c |",field[h][i]);
			
		}
		printf("\n");
		j++;
	}

	printf("%c%c%c%c--- --- --- --- --- ---\n",space,space,space,space);

	printf("     ");
	for(int i = 1; i <= columns; i++)
	{
		printf("%d   ",i);
	}
	printf("\n");
}
void down_possible(const int rows, const int columns, char field[rows][columns], int x, int y)
{
	
}
