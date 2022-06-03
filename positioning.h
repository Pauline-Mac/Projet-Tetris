#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void create_game(char GameGrid[][10]);

int check_room(char game[10][10], int column, int line, const char tetrimo[4][4]);

int get_lowest_line(char game[10][10], int column, const char tetrimo[4][4], int random);

int place_block(const char tetrimimo[4][4], char game[10][10])
