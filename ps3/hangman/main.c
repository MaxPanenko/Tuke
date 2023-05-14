#include <stdio.h>
#include "hangman.h"
#include <time.h>
#include <stdlib.h>
int main() {
srand(time(NULL));

char word[30];
get_word(word);
char result[30];
printf("%d\n", is_word_guessed("secret", "aeiou"));
// prints: 0
printf("%d\n", is_word_guessed("hello", "aeihoul"));
// prints: 1
get_guessed_word("container", "arpstxgoieyu", result);

char result1[30];
get_available_letters("arpstxgoieyu", result1);
// result = "bcdfhjklmnqvwz"
return 0;
}
