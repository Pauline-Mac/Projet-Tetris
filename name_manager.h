
#ifndef NAME_MANAGER_H
	#define NAME_MANAGER_H
	#include "main.h"
	void get_alias(char alias[101], FILE* fp, int* nbline, int* updateScore);

	void end_game_score(char alias[101], int* ScorePlayer,FILE* fp, int* updateScore, int* nbline);
#endif
