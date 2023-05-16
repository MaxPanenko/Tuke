#include <stdio.h>
#include "hangman.h"
#include <time.h>
#include <stdlib.h>
int main() 
{
srand(time(NULL));

char word[30];
get_word(word);
hangman(word);
return 0;
}
