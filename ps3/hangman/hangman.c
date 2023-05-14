#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "hangman.h"
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


void hangman(const char secret[])
{
	
    int length = strlen(secret);
    printf("Welcome to the game, Hangman!\n");
    printf("I am thinking of a word that is %d letters long.\n",length);
    printf("-------------\n");

    int attempts = 8;
    char alpfavit[] = "abcdefghijklmnopqrstuvwxyz";
    char bukvi[30];
    char slovechko[30];
    char pomichnik[30];
    char gotov[30];
    while(attempts != 0) {

    printf("You have %d guesses left.\n", attempts);
    
    get_available_letters(gotov, bukvi);

    printf("Available letters: %s\n", bukvi);
    printf("Please guess a letter: ");
    scanf("%s", slovechko);
    int slovechkoL = strlen(slovechko);
    if(slovechko == NULL)
    {
    	break;
    }
    
    for(int i = 0 ; i < slovechkoL ; i++) 
    {
        if(isupper(slovechko[i])) 
        {
            slovechko[i] = tolower(slovechko[i]);
        }
        else
        {
        	continue;
        }
    }
    
    if(attempts > 0 && slovechko != NULL)
    {
    	get_guessed_word(secret, slovechko, pomichnik);
        strcat(gotov, slovechko);
    }
    
    
    if(length == slovechkoL) 
    {
        if(strcmp(secret,slovechko) == 0) 
        {
            printf("Congratulations, you won!\n");
            break;
        } 
         else 
         {
            printf("Sorry bad guess. The word was %s.\n", secret);
            break;
         }
        
    } 
    else if(slovechkoL > 1 && slovechkoL != length) 
    {
        printf("Sorry bad guess. The word was %s.\n", secret);
        break;
    }
    
    const int che = strlen(pomichnik);
    int finish = 0;
    int help = 0;
    int count = 0;
    
    for(int i = 0 ; i < slovechkoL ; i++) 
    {
        finish = 0;
        for(int j = 0 ; j < che ; j++) 
        {
            if(slovechko[i] == pomichnik[j]) 
            {
                finish++;
                count --;
            }
        }
    }
    int str = strlen(bukvi);
    int i = 0;
    int j = 0;
    while(i < slovechkoL)
    {
    	while(j < str)
    	{
    		if(slovechko[i] == bukvi[i]) 
            	{
                	help++;
            	}
            	j++;
    	}
    	i++;
    }
    
    for(int i = 0 ; i < slovechkoL ; i++) 
    {
        for(int j = 0 ; j < str ; j++) 
        {
            if(slovechko[i] == bukvi[i]) 
            {
                help++;
            }
        }
    }
    
    if(strspn(slovechko , alpfavit) == 0) 
    {
        printf("Oops! '%s' it's incorrect format ", slovechko);
    }
    
    if(finish == 0) 
    {
        printf("Oops! That letter is not in my word: ");
        attempts--;
    }  
    else
    
    if(finish > 0) 
    {
        printf("Good guess: ");
    }
    
    int reverse = che;
    
    int s = 0;
    while(s < reverse)
    {
    	if(s == reverse - 1) 
        {
            printf("%c", pomichnik[s]);
            break;
        }
        else
        {
        	printf("%c ", pomichnik[s]);
        }  
        s++;
    }
    
        printf("\n");
        printf("-------------\n");
        if(is_word_guessed(secret , pomichnik) == true) 
        {
            printf("Congratulations, you won!\n");
            break;
        } 
        else
        {
		if(attempts == 0 ) 
		{
			printf("Sorry, you ran out of guesses. The word was %s.\n" , secret);
			break;
       	        }
	}
	
 }
}

void get_available_letters(const char letters_guessed[], char available_letters[])
{			 
    
    char alfavit[] = "abcdefghijklmnopqrstuvwxyz";
    int bukvi = strlen(letters_guessed);
    int length=strlen(alfavit);
    int y = 0;
       
        for(int i = 0 ; i < length ; i++) 
        { 
            int n = 0;
            for(int j = 0; j < bukvi ; j++) 
            {
                if(alfavit[i] == letters_guessed[j]) 
                {
                    n++;
                } 
            } 
            if(n == 0) 
            {
                available_letters[y]=alfavit[i];
                y++;
            }
        }
        available_letters[y] = '\0';
	
	
}

void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[])
{
	int length = strlen(secret);
    	int sizeguessed = strlen(letters_guessed);
    	int i = 0;
    	while(i != length)
    	{
    	for(int j = 0 ; j != sizeguessed ; j++) 
            {
                if(secret[i] == letters_guessed[j]) 
                {
                    guessed_word[i] = letters_guessed[j];
                } 
            }
            
                if(guessed_word[i] != secret[i]) 
                {
               		 guessed_word[i] = '_';
                }
            	i++;
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
