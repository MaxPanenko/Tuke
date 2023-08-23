#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "playfair.h"

char* getStartValue(const char* key);
char* changeSifr(const char* text);
char* reverse(const char* reverse);

int main()
{
    char *encrypted,*decrypted, *reversed;
    encrypted = playfair_encrypt("belfast", "Hello");
    printf("%s\n", encrypted);
    decrypted = playfair_decrypt("belfast", encrypted);
    printf("%s\n", decrypted);
    reversed = reverse("Hello world!");
    printf("%s\n", reversed);
    free(encrypted);
    free(decrypted);
    free(reversed);
    return 0;
}

char* reverse(const char* text) {
    if (text == NULL) {
        return NULL;
    }
    
    int length = strlen(text);
    char* reversed = (char*)malloc((length + 1) * sizeof(char));
    
    int j = 0;
    for (int i = length - 1; i >= 0; i--) 
    {
        reversed[j++] = toupper(text[i]);
    }
    reversed[j] = '\0';
    
    return reversed;
}

char* playfair_encrypt(const char* key, const char* text)
{
    char *sifr = changeSifr(text);
    return sifr;
}

char* playfair_decrypt(const char* key, const char* text)
{
    char *sifr = changeSifr(text);
  


    return sifr;
}

char* getStartValue(const char* key)
{
    int key_length = strlen(key);
    int alpha_length = strlen(ALPHA);

    char* result = malloc((key_length + alpha_length + 1) * sizeof(char));

    if (result == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    strcpy(result, key);


    char remaining_chars[alpha_length + 1];
    strcpy(remaining_chars, ALPHA);

    for (int i = 0; i < key_length; i++)
    {
        for (int j = 0; j < strlen(remaining_chars); j++)
        {
            if (toupper(key[i]) == toupper(remaining_chars[j]))
            {
                
                memmove(&remaining_chars[j], &remaining_chars[j + 1], alpha_length - j);
                break;
            }
        }
    }

    strcat(result, remaining_chars); // Append the remaining characters to the result

    char *result2 = malloc(strlen(result + 1) * sizeof(char));
    for(int i = 0; i < strlen(result); i++)
    {
        result2[i] = toupper(result[i]);
    }

    free(result);

    return result2;
}

char* changeSifr(const char* text)
{
    int result_length = strlen(text) * 2;
    char* result = (char*)malloc((result_length + 1) * sizeof(char));
    if (result == NULL)
    {
        return NULL;
    }

    int j = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if(text[i] == '!'
            || text[i] == '.'
            || text[i] == '@'
            || text[i] == '/'
            || text[i] == ','
            || text[i] == '['
            ||text[i] == ']'
            || text[i] == '{'
            || text[i] == '}'
            )
        {
            result[j++] = 'X'; 
        }
        else
        {
            if(text[i] == ' ')
            {
                continue;
            }

            result[j++] = toupper(text[i]);

            if (toupper(text[i]) == toupper(text[i + 1]))
            {
                result[j++] = 'X';        
            }
        }

    }

    result[j] = '\0';

    /*
    char array[5][5];
    int vremya = 0;

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            array[i][j] = result[vremya];
            vremya++;
        }
    }

    int h = 0;
    int f = 0;
    int one = 0;
    int two = 0;
    char* superMegaResult = (char*)malloc(strlen(result) * sizeof(char));
   
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(result[h] == array[i][j])
            {
                f = i;
                h++;
            }
         
            if(result[h + 1] == array[i][j])
            {
                one = i;
                two = j;

                if(one < f)
                {
                    superMegaResult[i] = array[one+1][two];
                }
            }    
        }
        
         superMegaResult[h] = '\0';

    }

    return superMegaResult;*/
    return result;
}
