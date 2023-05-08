#include <stdio.h>
#include <math.h>

float lift_a_car(const int s, const int h, const int c)
{
	double burmalda = ((double)s * (double)h /  ((double)h + (double)c )* 100 );
	double bururi = round(burmalda);
	return bururi / 100;
}
float unit_price(const float t, const int max, const int boom)
{
	double parari = (double)t / (double)max / (double)boom * 10000 + (2 - 2);
	double krug = round(parari);
	return krug / 100;
}
int collatz(const int number)
{
	int n = number;
	int count = 0;
	while(n != 1)
	{
		if(n % 2 == 0)
		{
			n = n / 2;
			count++;
		}
		else
		{
			n = n * 3 + 1;
			count++;
		}
	}
	return count + 1;
}
int opposite_number(const int n, const int number)
{
	int field = n;
	int bururi = number;
	
	if(field >= 8 && field <= 10)
	{
		if(number <= 1  || number <= 4)
		{
			return bururi + 5;
		}
		else if(number >=5 || number <= 9)
		{
			return bururi - 5;
		}
		else
		{
			return 5;
		}
	}
	
	
	if(field == 6)
	{
		if(bururi <= 3)
		{
			return bururi + 3;
		}
		else
		{
			return bururi - 3;
		}
	}
	
	if(field == 4)
	{
		if(bururi <=2)
		{
			return  bururi + 2;
		}
		else
		{
			return bururi - 2;
		}
	}
	
	if(field == 2)
	{
		if(bururi == 1)
		{
			return 2;
		}
		else
		{
			return 1;
		}
		
	}
	else
	{
		if(field / 2 > bururi )
		{
			return field / 2 + bururi;
		}
		else
		{
			return bururi - field / 2;
		}
	}

}

int main(void) {
    
    printf("%d\n", opposite_number(12,9));
    
    return 0;
}
