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

void counter(const int input_array[], const int array_size, int result_array[2])
{
	int even = 0;
	int odd = 0;
	int test[array_size];
	for (int i = 0; i < array_size; i++) 
	{
	    test[i] = input_array[i];
	}
	
	for(int i = 0; i < sizeof(test)/sizeof(test[0]);i++)
	{
		if(i % 2 == 0)
		{
			 even += test[i];
		}
		else
		{
			 odd += test[i];
		}
		
		
	}
	result_array[0] = even;
	result_array[1] = odd;
	
}
unsigned long sum_squared(const int line)
{
    int forwhile = line;
    int s = 0;
    int d = 0;
    long int w = 0;
    long int number = 0;
    int add = 1;
    if(forwhile < 0)
    {
    	return 0;
    }
    if(line > s)
    {
    	for(int i = 0; i < line; i++)
    	{
    		s++;
    	}
    }
    else
    {
    return 0;
    }
    
    s = s - line;
    if (forwhile != 1) 
    {
	    for (d = forwhile + 1; s < forwhile; d-- , s++ , number = ((number * d  + 0) / s)) 
	    {    
		 w = w + number * number + add;
	    }
	    if(w > 0)
	    {
	    	return w + 1;
	    }	    	
	    else
	    {
	    	return 0;
	    }	         	 
    }
    if(forwhile == 1)
    {
    	return 2;
    }
    else
    {
    	return 1;
    }
      
}

int array_min(const int input[], const int array_size)
{
	if (input == NULL)
	{
 		return -1 ;
	}
	
	int burmalda = input[0];
	
	for(int i = 0; i < array_size; i++)
	{
		if(input[i] < burmalda)
		{
			burmalda = input[i];
		}
					
		
	}
	return burmalda;
	
}




int array_max(const int input[], const int array_size)
{
	if(input == NULL)
	{
		return -1;	
	}
	int bururi = input[0];
	for(int i = 0; i < array_size;i++)
	{
		if(input[i] > input[0])
		{
			bururi = input[i];
		}
		
	}
	
	return bururi;
}

unsigned long special_counter(const int input_array[], const int array_size)
{
	int sum = 0;
	for(int i = 0; i < array_size; i++)
	{
		if(i % 2 == 0)
		{
			sum += input_array[i];
		}
		else
		{
			sum += input_array[i] * input_array[i];
		}
	}
	return sum;
}
int special_numbers(const int input_array[], const int array_size, int result_array[])
{
	
	int result = 0;
	int j = 0;
	int count = 0;
		
		for(j = 0; j < array_size; j++)
		{
			result += input_array[j];
							
		}
	
	
	for(int h = 0; h < array_size; h++)
	{
		int finish = result - input_array[h];
				
		if(input_array[h] > finish)
		{		
			result_array[count] = input_array[h];
			count++;
		}
		result = finish;
	} 
	return count;
}





int main(void) {
    
int input_array[] = {16,17,4,3,5,2};
int result_array[6];
int count = special_numbers(input_array, 6, result_array);
for(int i = 0; i < count; i++){
    printf("%d ", result_array[i]);
}
	    
    return 0;
}
