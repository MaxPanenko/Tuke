#include <stdbool.h>

#define BLANK ' '

void game_field(const int rows, const int columns, char field[rows][columns]);

bool check(const int rows, const int columns, char field[rows][columns]);

void down_possible(const int rows, const int columns, char field[rows][columns], int x, int y);

void generator(const int rows, const int columns, char field[rows][columns]);

void ball_sort_puzzle();

