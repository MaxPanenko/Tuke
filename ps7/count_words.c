#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char* argv[])
    {
    	FILE* fp = fopen(argv[1],"r");	
    	
    	if (fp == NULL) 
    	{
           printf("Failed\n");
           return 1;
        }

        int count = 0;
        char word[] = "ananas";
        int start = fgetc(fp);
        bool truth = true;
        while (start != EOF) 
        {
           
           for (int i = 0; i < 6; i++) 
           {
               if (toupper(ch) != toupper(word[i])) 
               {
                    truth = false;
                    break;
               }

                ch = fgetc(fp);
           }
           
           if (truth = true) 
           {
               count++;
           }
        }

        fclose(fp);

	return count;	
}