#include<stdio.h>
#include<stdbool.h>
#include<string.h>

void bytes_to_blocks(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]);
void blocks_to_bytes(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]);
void decode_bytes(const int rows, bool bytes[rows][8], char string[rows]);
void encode_string(const char string[], bool bytes[strlen(string)+1][8]);
void encode_char(const char character, bool bits[8]);
char decode_byte(const bool bits[8]);


int main()
{	
int length = 4+1, cols = 3, offset = 2;
bool bytes1[4+1][8] = {
    {0,1,0,0,0,0,0,1},
    {0,1,1,0,1,0,0,0},
    {0,1,1,0,1,1,1,1},
    {0,1,1,0,1,0,1,0},
    {0,0,0,0,0,0,0,0}
};
bool blocks1[offset*8][cols];
bytes_to_blocks(cols, offset, blocks1, length, bytes1);
for(int j = 0; j < offset*8; j++){
    for(int i = 0; i < cols; i++){
        printf("%d ", (blocks1[j][i] == true) ? 1 : 0);
    }
    printf("\n");
    if(j % 8 == 7){
        printf("\n");
    }
}
// prints:
// 0 0 0 
// 1 1 1 
// 0 1 1 
// 0 0 0 
// 0 1 1 
// 0 0 1 
// 0 0 1 
// 1 0 1 
// 
// 0 0 0 
// 1 0 0 
// 1 0 0 
// 0 0 0 
// 1 0 0 
// 0 0 0 
// 1 0 0 
// 0 0 0

bool blocks2[2*8][3] = {
    {0,0,0},
    {1,1,1},
    {0,1,1},
    {0,0,0},
    {0,1,1},
    {0,0,1},
    {0,0,1},
    {1,0,1},
    {0,0,0},
    {1,0,0},
    {1,0,0},
    {0,0,0},
    {1,0,0},
    {0,0,0},
    {1,0,0},
    {0,0,0}
};
bool bytes2[length][8];
blocks_to_bytes(3, 2, blocks2, length, bytes2);
for(int j = 0; j < length; j++){
    for(int i = 0; i < 8; i++){
        printf("%d", bytes2[j][i]);
    }
    printf("\n");
}
// prints:
// 01000001
// 01101000
// 01101111
// 01101010
// 00000000

}

void blocks_to_bytes(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8])
{
	for(int i = 0; i < cols; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			bytes[i][j] = blocks[j][i];
		}
	}

	int check = cols;
	for(int i = 0; i < cols && check != rows; i++)
	{
		for(int h = 8,f = 0; h < 17; h++, f++)
		{
			bytes[check][f] = blocks[h][i];
		}

		check++;
	}
}

void bytes_to_blocks(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8])
{
     
    memset(blocks, 0, sizeof(bool) * offset * 8 * cols);

	for(int i = 0; i < cols ; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			blocks[j][i] = bytes[i][j];
		}
	}

	int n = cols;
	for(int i = 0; i < cols && n != rows; i++)
	{

		for(int h = 8,f = 0; h < 17; h++,f++)
		{

			blocks[h][i] = bytes[n][f];
		}

		n++;

	}
	
	
				
}

void decode_bytes(const int rows, bool bytes[rows][8], char string[rows])
{
	for(int i = 0; i < rows; i++)
	{
		bool bite[8];

		for(int j = 0; j < 8; j++)
		{
			bite[j] = bytes[i][j];
		}

		string[i] = decode_byte(bite);
	}
}

void encode_string(const char string[], bool bytes[strlen(string)+1][8])
{
	int length = strlen(string)+1;
	int value = 0;
	bool test[8];

	for(int i = 0; i < length; i++)
	{
		bytes[i][0] = string[i];
		encode_char(string[i],test);

		for(int f = 0; f < 8;f++)
		{
			bytes[i][f] = test[f];
		}
	}
}

char decode_byte(const bool bits[8])
{
 	char start = 0;

    for (int i = 0; i < 8; i++) 
    {
       start *= 2;
       start += bits[i]; 
    }

    return start;
}

void encode_char(const char character, bool bits[8])
{
	int convert = character;

	for(int i = 7; i >= 0; i--)
	{
		
		if(convert % 2 == 0)
		{
			bits[i] = 0;
		}
		else
		{
			bits[i] = 1;
		}
		convert /= 2;
	}
}
