

#ifndef LINE_VERIF_H
	#define LINE_VERIF_H
	#include "main.h"
	int verif_line (char tab[][10], int line);

	void eraser(char tab[][10], int line);

	void table_descent (char tab[][10], int line);

	int check_line_for_score(char tab[10][10], int* scr);
#endif
