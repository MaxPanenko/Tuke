#include <stdio.h>
#include <stdlib.h> 
#include "ballsortpuzzle.h"
#include <string.h>


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
	printf("%c%c%c%c",space,space,space,space);
	int s = 0;

	while(s < columns)
	{
		printf("--- ");
		s++;
	}
	printf("\n");

	printf("     ");
	for(int i = 1; i <= columns; i++)
	{
		printf("%d   ",i);
	}
	printf("\n");
}
void down_possible(const int rows, const int columns, char field[rows][columns], int x, int y)
{
	 int pole = 0;
	 char hesh = ' ';
	 	  
	 for(int i = 0; i < rows; i++)
	 {
	 	int prikol = i;
	 	for(int j = 1; j <= columns; j++)
	 	{
	 		if(j == x)
	 		{
	 			prikol = 0;
	 			if(field[prikol][x - 1] == ' ')
	 			{
	 				
	 				while(field[prikol][x - 1] == ' ')
	 				{
	 					prikol++;
	 				}
	 				hesh = field[prikol][x - 1];
	 				field[prikol][x - 1] = ' ';

	 				if(field[pole][y - 1] == ' ' &&  field[pole + 1][y - 1] == ' ')
	 				{
		 				while(field[pole][y - 1] == ' ' && pole != rows -1)
		 				{ 				
		 					pole++;
		 				}
		 				field[pole][y - 1] = hesh;
	 				}

	 				if(field[pole][y - 1] == ' ')
	 				{
	 					field[pole][y - 1] = hesh;
	 				}
	 			}	

	 			else
	 			{
	 				prikol = 0;
	 				hesh = field[prikol][x - 1];
	 				field[prikol][x - 1] = ' ';

	 				if(field[pole][y - 1] == ' ' &&  field[pole + 1][y - 1] == ' ')
	 				{
		 				while(field[pole][y - 1] == ' ' && pole != rows -1)
		 				{ 				
		 					pole++;
		 				}
		 				field[pole][y - 1] = hesh;
	 				}

	 				if(field[pole][y - 1] == ' ')
	 				{
	 					field[pole][y - 1] = hesh;
	 				}
	 			}

	 		pole = 0;
	 		generator(4,6,field);
	 		break;
	 		}		
	 	}
	 	break;
	 }		
}

bool check(const int rows, const int columns, char field[rows][columns])
{
	bool winOrLose = true;
	
	for(int i = 0; i < columns; i++)
	{
		char first = field[0][i];

		for(int j = 1; j < rows; j++)
		{
			if (field[j][i] != first)
            {
                return false;
            }
		}
	}
	return winOrLose;
}

void game_field(const int rows, const int columns, char field[rows][columns])
{
	int columnsMultiplay = (columns * 4 + 4 );
	int ray = (columns * 4 + 4 ) / 2 - 3;
	int test = ray;
	int check = 0;
	int k = 1;
	int f = 0;	

	for(int i = 0; i < columnsMultiplay; i++)
	{
		for(int j = 0; j < ray + 2; ray--)
		{
			printf(" ");
			check = j;
		}
		ray = test - 1;
		test--;
		printf("/");

	
	for (f = 0;f < k; f++)
	{
   		 printf("  ");
	}

	k++;
	f = 0;

		
		printf(" \\\n");

		if(check >= ray)
		{
			break;
		}

	}
}










