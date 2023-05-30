#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ncurses.h>
#include <time.h>
#include <stdlib.h>

#define LOOT '#'
#define PLAYER '@'
#define ELEMENT_OF_FIELD '.'
#define RANDOM_ITEMS rand() % 15 + 10

typedef struct {
    int x;
    int y;
} Position;

void draw_field(int random_width, int random_height) 
{

    for (int x = 0; x < random_width; x++) 
    {
    	
        for (int y = 0; y < random_height; y++) 
        {
            mvprintw(y, x, ".");
            refresh();
        }
   
    }
}

void draw_player(Position player) 
{
    mvprintw(player.y, player.x, "%c", PLAYER);
}

void draw_loot(Position item) 
{
    if (item.x != -1) {
        mvprintw(item.y, item.x, "%c", LOOT);
    }
}


int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    srand(time(NULL));

    int random_width = rand() % 20 + 15;
    int random_height = random_width / 2;
    int rnd_pos = rand() % 2 + 5;

    Position player = {random_width - rnd_pos, random_height - rnd_pos};
    Position items[RANDOM_ITEMS];
    

    bool end_or_win = false;
    
    clear();
    draw_field(random_width, random_height);
    


    // End
    getchar();
    endwin();
    return 0;
}



