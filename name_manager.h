#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void get_alias(char alias[101], FILE* fp, int* nbline, int* updateScore);

void end_game_score(char alias[101], int* ScorePlayer,FILE* fp, int* updateScore, int* nbline);
