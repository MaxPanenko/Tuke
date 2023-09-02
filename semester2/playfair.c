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
    encrypted = playfair_encrypt("world", "Hello");
    printf("%s\n", encrypted);
    decrypted = playfair_decrypt("world", encrypted);
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
    char *sifr = getStartValue(key);
    char *word = changeSifr(text);
    char *result = (char*)malloc((strlen(word) * 2 + 1) * sizeof(char));

    if (sifr == NULL || word == NULL || result == NULL) {
        // Handle memory allocation failure here
        return NULL;
    }

    int lengthArray = strlen(sifr);

    char *twoDArray = (char*)malloc(lengthArray * sizeof(char)); 

    if (twoDArray == NULL) {
        // Handle memory allocation failure here
        free(sifr);
        free(word);
        free(result);
        return NULL;
    }

    for(int i = 0; i < lengthArray; i++)
    {
        twoDArray[i] = sifr[i];
    }

    twoDArray[lengthArray] = '\0';

    int currentNumber[strlen(word)];
    int changeNumber = 0;
    for(int i = 0; i < strlen(word) / 2 ; i++) 
    {
        for(int j = 0; j < strlen(twoDArray); j++)
        {
            if(word[i] == twoDArray[j] || word[i + 1] == twoDArray[j])
            {
                currentNumber[changeNumber] = j;
                changeNumber++;
            }
        }

        if(changeNumber > 1 && currentNumber[i] + 1  < currentNumber[i + 1])
        {
            if (currentNumber[i] + 1 < currentNumber[i + 2]){
                strcat(result, &twoDArray[currentNumber[i - 2]]);
                strcat(result, &twoDArray[currentNumber[i + 3]]);
                strcat(result, " ");
            }
        }
    }
    
    free(sifr);
    free(word);
    free(twoDArray);
    return result;
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

            if (toupper(text[i]) == toupper(text[i + 1]) && toupper(text[i] + 1) != toupper(text[i + 2]))
            {
                result[j++] = 'X';        
            }
        }

    }

    result[j] = '\0';




    return result;
}
