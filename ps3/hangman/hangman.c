#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "hangman.h"
#include <stdbool.h>
#include <string.h>

void get_available_letters(const char letters_guessed[], char available_letters[])
{			 
	int h = 0;
	char letters[] = "abcdefghijklmnopqrstuvwxyz";
	int length = strlen(letters);
	int length2 = strlen(letters_guessed);
	

	for(int i = 0; i < length; i++)
	{
	char skip = letters_guessed[i];
	
		for(int j = 0; j < length2; j++)
		{
			if(letters[i] == letters_guessed[j])
			{
				skip = 'g';
				
			}
																			
		}
		if(skip == letters_guessed[i])
		{
			available_letters[h] = letters[i];
			h++;
				
		}
	}
	available_letters[strlen(letters)] = '\0';
	
	printf("%s\n", available_letters);
}





























void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[])
{
	int length = strlen(secret);
	
	for(int i = 0; i < length; i++)
	{
		for(int j = 0; j < length; j++)
		{
			if(secret[i] == letters_guessed[j])
			{	
				guessed_word[i] = letters_guessed[j];
				break;
			}
			else
			{
				guessed_word[i] = '_';
			}
		}
		
	}
	guessed_word[length] = '\0';
	
}

int is_word_guessed(const char secret[], const char letters_guessed[])
{
	int length = strlen(secret);
	int length2 = strlen(letters_guessed);
	bool ugadano[length];
	memset(ugadano, false, sizeof(ugadano));
	
	for(int i = 0; i < length;i++)
	{
		if (ugadano[i])
		{
			continue;
		}
		    
		for(int j = 0; j < length2 ;j++)
		{
			if (!ugadano[i] && secret[i] == letters_guessed[j])
			{
				ugadano[i] = true;				
				break;
			}	
		}
	}
	
	 for (int i = 0; i < length; i++)
   	 {
       		 if (!ugadano[i])
     	         {
            		return 0;
                 }
   	 }
   	 
   	 return 1;
	
	
}

int get_word(char secret[]){
    // check if file exists first and is readable
    FILE *fp = fopen(WORDLIST_FILENAME, "rb");
    if( fp == NULL ){
        fprintf(stderr, "No such file or directory: %s\n", WORDLIST_FILENAME);
        return 1;
    }

    // get the filesize first
    struct stat st;
    stat(WORDLIST_FILENAME, &st);
    long int size = st.st_size;

    do{
        // generate random number between 0 and filesize
        long int random = (rand() % size) + 1;
        // seek to the random position of file
        fseek(fp, random, SEEK_SET);
        // get next word in row ;)
        int result = fscanf(fp, "%*s %20s", secret);
        if( result != EOF )
            break;
    }while(1);

    fclose(fp);

    return 0;
}
