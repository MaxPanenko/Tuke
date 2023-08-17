#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "playfair.h"

char* getStartValue(const char* key);
char* playfair_encrypt(const char* key, const char* text);

int main()
{
    char *encrypted;
    encrypted = playfair_encrypt("SECRETKEY", "HELLOWORLD");
    printf("%s\n", encrypted);
    free(encrypted);
    return 0;
}

char* playfair_encrypt(const char* key, const char* text)
{
    char* startValue = getStartValue(key); // Call getStartValue

    // Process startValue (encrypt or manipulate it)

    return startValue; // Return it without freeing
}

char* getStartValue(const char* key)
{
    char* result = malloc((strlen(key) + strlen(ALPHA) + 1) * sizeof(char));
    strcpy(result, key);

    char remaining_chars[strlen(ALPHA) + 1];
    strcpy(remaining_chars, ALPHA);

    int key_length = strlen(key);
    for (int i = 0; i < key_length; i++)
    {
        for (int j = 0; j < strlen(remaining_chars); j++)
        {
            if (key[i] == remaining_chars[j])
            {      
                remaining_chars[j] = remaining_chars[j+1];
                remaining_chars[j+1] = '\0';
                break;
            }
        }
    }

    strcat(result, remaining_chars); // Append the remaining characters to the result

    return result;
}
