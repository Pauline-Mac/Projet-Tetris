#include <stdio.h>

typedef struct{
	char** rotat;
}Piece;

void display(char tab[10][10]){
	puts("    __ _______         __         __         __   ");
	puts("  ,' _|_     _|.-----.|  |_.----.|__|.-----.|_ `. ");
	puts(" /  /   |   |  |  -__||   _|   _||  ||__ --|  \\  \\ ");
	puts(" \\  \\_  |___|  |_____||____|__|  |__||_____| _/  / ");
	puts("  `.__|                                     |__,' ");
	puts("");
	puts("");
	
	for (int i=0; i<10; i++){
		printf("|");
		for(int j=0; j<10; j++){
			printf("%c", tab[i][j]);
			printf("|");
		}
		puts("");
	}
}

int check_room(char game[10][10], int colomn, int line, char tetrimo[4][4], int lowest_block_x, int lowest_block_y){
	// check if there is room for the whole tetrimimo
	int place=1;
	while (place==1){
		for (int i =0; i< 4; i++){
			for (int j= 0; j< 4 ;j++){
				if (tetrimo[i][j] == '@' && game[line+i][colomn + j] == '@'){
					place = 0;
				}
			}
		}
	}
	return place;
}


int get_lowest_line(char game[10][10], int colomn, char tetrimo[4][4], int lowest_block_x, int lowest_block_y){
	// This fonction return the index number of the lowest line that isn't already '@'
	// If colomn is alredy full it returns -1
	int ln =9;
	while(ln >= 0){
		if( game[ln][colomn] == '_'){
			if ( check_room(game,colomn,ln,tetrimo, lowest_block_x, lowest_block_y) == 1){
				return ln;
			}
			else{
				ln++;
			}
		}
		else {
			ln++;
		}
		
	}
	puts("Colomn already full");
	return -1;
}



		
	

void place_block(char tetrimimo[4][4], char game[10][10], int lowest_block_x, int lowest_block_y){
	int colomn;
	puts("Choose colomn.");
	scanf("%d",&colomn);
	// 1 tetrimimo is only composed of 4 blocks
	int line;
	/*
	int col_lw = colomn + lowest_block_y;
	if ( col_lw >10){
		col_lw = 10;
	}*/
	line = get_lowest_line(game, colomn, tetrimimo, lowest_block_x,lowest_block_y);
	while(line!=-1){
		for(int i=0; i< 4; i++){
			for(int j = 0; j< 4; j++){
				if (tetrimimo[i][j] == '@'){
					game[i][j] = '@';
				}
			}
		}
	}						
}

	
	
	
	
	

int main(int argc, char **argv)
{
	char game[10][10] = {0};
	for (int i = 0; i<10; i++){
		for(int j=0; j<10; j++){
			game[i][j] = '_';
		}
	}
	display(game);
	
	char cube[4][4] = {{'@','@','_','_'},{'@','@','_','_'},{'_','_','_','_'},{'_','_','_','_'}};
	place_block(cube, game,1,1);
	display(game);
	return 0;
}	
