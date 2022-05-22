#include <stdio.h>
#include <stdlib.h>


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

int check_room(char game[10][10], int column, int line, char tetrimo[4][4]){
	// check if there is room for the whole tetrimimo
	int place=1;
	if (place==1){
		for (int i =4; i>0; i--){
			for (int j= 0; j< 4 ;j++){
				if (tetrimo[i][j] == '@' && game[line+(i-3)][column + j] == '@'){
					return 0;
				}
			}
		}
	}
	return place;
	//return 1;
}


int get_lowest_line(char game[10][10], int column, char tetrimo[4][4]){
	// This fonction return the index number of the lowest line that isn't already '@'
	// If column is alredy full it returns -1
	int ln =9;
	while(ln >=0){
		if( game[ln][column] == '_'){
			if ( check_room(game,column,ln,tetrimo) == 1){
				return ln;
			}
			else{
				ln--;
			}
		}
		else {
			ln--;
		}
		
	}
	puts("You can not place your tetrimimo here");
	return -1;
}



		
	

void place_block(char tetrimimo[4][4], char game[10][10]){
	int column;int line;
	do{
		puts("Choose column.");
		scanf("%d",&column);
		//system("clear");
		line = get_lowest_line(game, column, tetrimimo);
	}while (line == -1);
	for(int i=4; i> 0; i--){
		for(int j = 0; j< 4; j++){
			if (tetrimimo[i][j] == '@'){
				game[line+(i-3)][column + j] = '@';
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
	
	char cube[4][4] = {{'_','_','_','_'},{'_','_','_','_'},{'@','@','_','_'},{'@','@','_','_'}};
	place_block(cube, game);
	display(game);
	place_block(cube, game);
	display(game);
	place_block(cube, game);
	display(game);
	place_block(cube, game);
	display(game);
	place_block(cube, game);
	display(game);
	place_block(cube, game);
	display(game);
	return 0;
}	
