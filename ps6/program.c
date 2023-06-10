#include <stdio.h>
#include <ncurses.h>
#include <time.h>
#include <stdlib.h>

#define LOOT '$'
#define PLAYER '@'
#define ELEMENT_OF_FIELD '.'
#define ENEMY 'v'
#define ENEMYUP '^'

typedef struct {
    int x;
    int y;
} Position;

void move_enemy(Position* enemy_pos, int random_width, int random_height) {
    if (enemy_pos->y < random_height - 1) {
        mvprintw(enemy_pos->y, enemy_pos->x, "%c", ELEMENT_OF_FIELD);
        enemy_pos->y++;
        mvprintw(enemy_pos->y, enemy_pos->x, "%c", ENEMY);  
    }
}

void move_enemy_forward(Position* enemy_pos, int random_width, int random_height) {
    if (enemy_pos->y > 0) {
        mvprintw(enemy_pos->y, enemy_pos->x, "%c", ELEMENT_OF_FIELD);
        enemy_pos->y--;
        mvprintw(enemy_pos->y, enemy_pos->x, "%c", ENEMYUP);  
    }  
}

void draw_enemy(Position enemy_pos) {
    mvprintw(enemy_pos.y, enemy_pos.x, "%c", ENEMY);
}

void draw_field(int random_width, int random_height) {
    for (int x = 0; x < random_width; x++) {
        for (int y = 0; y < random_height; y++) {
            mvprintw(y, x, "%c", ELEMENT_OF_FIELD);
        }
    }
}

void draw_player(Position player) {
    mvprintw(player.y, player.x, "%c", PLAYER);
}

void draw_loot(Position item) {
    if (item.x != -1) {
        mvprintw(item.y, item.x, "%c", LOOT);
    }
}

Position generate_random_position(int random_width, int random_height) {
    Position pos;
    pos.x = rand() % (random_width - 3) + 3;
    pos.y = rand() % random_height;
    return pos;
}

void move_player(Position* player, int direction, int random_width, int random_height) {
    Position new_position = *player;
    switch (direction) {
        case 0:  // Up
            new_position.y--;
            break;
        case 1:  // Down
            new_position.y++;
            break;
        case 2:  // Left
            new_position.x--;
            break;
        case 3:  // Right
            new_position.x++;
            break;
    }

    if (new_position.x >= 0 && new_position.x < random_width && 
        new_position.y >= 0 && new_position.y < random_height) {
        *player = new_position;
    }
}

bool is_collision(Position a, Position b) {
    return (a.x == b.x && a.y == b.y);
}

void draw_hud(int level, int current_dollars, int random_width, int random_height) {
    mvprintw(random_height + 2, 0, "level:%d $:%d", level, current_dollars);
}

void sleep_ms(int milliseconds) {
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
}

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    nodelay(stdscr, TRUE);  // Enable non-blocking input

    srand(time(NULL));

    int level = 1;
    int max_level = 3;
    int random_items = rand() % 10 + 10;
    int current_dollars = 0;
    int h = 0;

    while (level <= max_level) {
        clear();

        int random_width = rand() % 20 + 15;
        int random_height = random_width / 2;
        int random_spawn_enemy = rand() % 6 + 1;

        Position player = {random_width / 2, random_height / 2};
        Position items[random_items];
        Position enemy_pos;

        int random = rand() % 4 + 1; 
        enemy_pos.x = random_width / random - 1;
        enemy_pos.y = 0;
        
        for (int i = 0; i < random_items; i++) {
            items[i] = generate_random_position(random_width, random_height);
        }

        bool end_or_win = false;
        int input;

        while (!end_or_win) {
            clear();
            draw_hud(level, current_dollars, random_width, random_height);
            refresh();
            draw_field(random_width, random_height);
            draw_player(player);
            draw_enemy(enemy_pos);
            refresh();

            for (int i = 0; i < random_items; i++) {
                draw_loot(items[i]);
            }

            if (h < random_height) {
                move_enemy(&enemy_pos, random_width, random_height);
                h++;
            } else {
                move_enemy_forward(&enemy_pos, random_width, random_height);
            }

            if (enemy_pos.y == 0) {
                h = 0;
            }

            input = getch();

            switch (input) {
                case KEY_UP:
                    move_player(&player, 0, random_width, random_height);
                    break;
                case KEY_DOWN:
                    move_player(&player, 1, random_width, random_height);
                    break;
                case KEY_LEFT:
                    move_player(&player, 2, random_width, random_height);
                    break;
                case KEY_RIGHT:
                    move_player(&player, 3, random_width, random_height);
                    break;
                case 'q':
                    end_or_win = true;
                    break;
            }

            bool all_items_collected = true;
            for (int i = 0; i < random_items; i++) {
                if (is_collision(player, items[i])) {
                    items[i].x = -1;  // Mark collected item as removed
                    current_dollars++;                    
                }
                if (items[i].x != -1) {
                    all_items_collected = false;
                }
            }

            if (all_items_collected) {
                end_or_win = true;
            }

            sleep_ms(100);  // Optional delay between iterations (100 milliseconds)
        }

        if (level < max_level) {
            mvprintw(random_height + 2, 0, "Congratulations! Level %d completed. Press any key to go forward.", level);
            refresh();
            getch();
        } else {
            mvprintw(random_height + 2, 0, "Congratulations! You completed all levels. Press any key to exit.");
            refresh();
            getch();
        }

        level++;
    }

    getchar();
    endwin();
    return 0;
}
