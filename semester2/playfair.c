#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "playfair.h"

char* getStartValue(const char* key);
char* playfair_encrypt(const char* key, const char* text);
char* changeSifr(const char* text);

int main()
{
    char *encrypted;
    encrypted = playfair_encrypt("SECRET", "Hello World!");
    printf("%s\n", encrypted);
    free(encrypted);
    return 0;
}

char* playfair_encrypt(const char* key, const char* text)
{
    char* startValue = changeSifr(text); // Call getStartValue

    // Process startValue (encrypt or manipulate it)

    return startValue; // Return it without freeing
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
            if (key[i] == remaining_chars[j])
            {
                
                memmove(&remaining_chars[j], &remaining_chars[j + 1], alpha_length - j);
                break;
            }
        }
    }

    strcat(result, remaining_chars); // Append the remaining characters to the result

    return result;
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
            result[j++] = toupper(text[i]);

            if (toupper(text[i]) == toupper(text[i + 1]))
            {
                result[j++] = 'X';        
            }
        }
       

    }

    result[j] = '\0';

    return result;
}
