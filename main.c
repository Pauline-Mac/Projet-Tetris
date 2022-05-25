#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>



const char PIECE_1[4][4][4] = {
	{{' ',' ',' ',' '},{' ',' ',' ',' '},{' ',' ',' ',' '},{'@','@','@','@'}},// straight
	{{'@',' ',' ',' '},{'@',' ',' ',' '},{'@',' ',' ',' '},{'@',' ',' ',' '}},
	{{' ',' ',' ',' '},{' ',' ',' ',' '},{' ',' ',' ',' '},{'@','@','@','@'}},
	{{'@',' ',' ',' '},{'@',' ',' ',' '},{'@',' ',' ',' '},{'@',' ',' ',' '}}
};
const char PIECE_2[4][4][4] = {
	{{' ',' ',' ',' '},{' ',' ',' ',' '},{'@','@',' ',' '},{'@','@',' ',' '}},// square
	{{' ',' ',' ',' '},{' ',' ',' ',' '},{'@','@',' ',' '},{'@','@',' ',' '}},
	{{' ',' ',' ',' '},{' ',' ',' ',' '},{'@','@',' ',' '},{'@','@',' ',' '}},
	{{' ',' ',' ',' '},{' ',' ',' ',' '},{'@','@',' ',' '},{'@','@',' ',' '}}			

};
const char PIECE_3[4][4][4] = {
	{{' ',' ',' ',' '},{' ',' ',' ',' '},{'@','@','@',' '},{' ','@',' ',' '}},// T
	{{' ',' ',' ',' '},{'@',' ',' ',' '},{'@','@',' ',' '},{'@',' ',' ',' '}},
	{{' ',' ',' ',' '},{' ',' ',' ',' '},{' ','@',' ',' '},{'@','@','@',' '}},
	{{' ',' ',' ',' '},{' ','@',' ',' '},{'@','@',' ',' '},{' ','@',' ',' '}}
};
const char PIECE_4[4][4][4] = {
	{{' ',' ',' ',' '},{' ',' ',' ',' '},{'@','@','@',' '},{'@',' ',' ',' '}}, // lambda
	{{' ',' ',' ',' '},{'@',' ',' ',' '},{'@',' ',' ',' '},{'@','@',' ',' '}},
	{{' ',' ',' ',' '},{' ',' ',' ',' '},{' ',' ','@',' '},{'@','@','@',' '}},
	{{' ',' ',' ',' '},{'@','@',' ',' '},{' ','@',' ',' '},{' ','@',' ',' '}},
};
const char PIECE_5[4][4][4] = {
	{{' ',' ',' ',' '},{' ',' ',' ',' '},{'@','@','@',' '},{' ',' ','@',' '}}, // gamma
	{{' ',' ',' ',' '},{'@','@',' ',' '},{'@',' ',' ',' '},{'@',' ',' ',' '}},
	{{' ',' ',' ',' '},{' ',' ',' ',' '},{'@',' ',' ',' '},{'@','@','@',' '}},
	{{' ',' ',' ',' '},{' ','@',' ',' '},{' ','@',' ',' '},{'@','@',' ',' '}},
};
const char PIECE_6[4][4][4] = {
	{{' ',' ',' ',' '},{' ',' ',' ',' '},{'@','@',' ',' '},{' ','@','@',' '}}, // Z
	{{' ',' ',' ',' '},{' ','@',' ',' '},{'@','@',' ',' '},{'@',' ',' ',' '}},
	{{' ',' ',' ',' '},{' ',' ',' ',' '},{'@','@',' ',' '},{' ','@','@',' '}},
	{{' ',' ',' ',' '},{' ','@',' ',' '},{'@','@',' ',' '},{'@',' ',' ',' '}}
};
const char PIECE_7[4][4][4] = {
	{{' ',' ',' ',' '},{' ',' ',' ',' '},{' ','@','@',' '},{'@','@',' ',' '}},// S
	{{' ',' ',' ',' '},{'@',' ',' ',' '},{'@','@',' ',' '},{' ','@',' ',' '}},
	{{' ',' ',' ',' '},{' ',' ',' ',' '},{' ','@','@',' '},{'@','@',' ',' '}},
	{{' ',' ',' ',' '},{'@',' ',' ',' '},{'@','@',' ',' '},{' ','@',' ',' '}}
};



void create_game(char GameGrid[][10]){

	for (int i = 0; i<10; i++){
		for(int j=0; j<10; j++){
			GameGrid[i][j] = '_';
		}
	}
}

int display_rotation(const char tab[][4][4]){
	int rotat_number=-1;
	int verif=0;
	int c;
	
	// display every rotation
	puts(" 0     1      2      3");
	for (int i=0; i<4; i++){
		for (int y=0; y<4; y++){
			for (int j=0; j<4;j++){
				printf("%c",tab[y][i][j]);
			}
			printf("   ");
		}
		puts("");
	}
	
	
	// gets correct rotation number
	do {
		puts("Enter rotation number");
		verif=scanf("%d",&rotat_number);
		while ((c = getchar()) != '\n' && c != EOF) { }
		
		
	}while( verif != 1 || rotat_number < 0 || rotat_number >= 4);
	return rotat_number;
	
}



/*_________This fonction display tetris logo and game grid_______*/
void display(char tab[10][10]){
	puts("    __ _______         __         __         __   ");
	puts("  ,' _|_     _|.-----.|  |_.----.|__|.-----.|_ `. ");
	puts(" /  /   |   |  |  -__||   _|   _||  ||__ --|  \\  \\ ");
	puts(" \\  \\_  |___|  |_____||____|__|  |__||_____| _/  / ");
	puts("  `.__|                                     |__,' ");
	puts("");
	puts("");
	
	for (int i=0; i<10; i++){
		printf("               |");
		for(int j=0; j<10; j++){
			printf("%c", tab[i][j]);
			printf("|");
		}
		puts("");
	}
}


int check_room(char game[10][10], int column, int line, const char tetrimo[4][4]){
	// check if there is room for the whole tetrimimo
	// return 1 if there is enough place, 0 if not
	int place=1;
	if (place==1){
		for (int i =4; i>=0; i--){
			for (int j= 0; j< 4 ;j++){
				if (line+(i-3) < 0 && tetrimo[i][j] == '@'){
					return 0;
				}
				if ( column + j > 9 && tetrimo[i][j] == '@'){
					return 0;
				}
				else if (tetrimo[i][j] == '@' && game[line+(i-3)][column + j] == '@'){
					return 0;
				}
			}
		}
	}

	return place;
	//return 1;
}


int get_lowest_line(char game[10][10], int column, const char tetrimo[4][4]){
	// This fonction return the index number of the lowest line that isn't already '@'
	// If column is alredy full it returns -1

	
	int ln =9;
	while(ln >=0){
		if( game[ln][column] == '_' || (tetrimo[3][0]=='_')){
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



		
	

void place_block(const char tetrimimo[4][4], char game[10][10]){
	int column;int line;
	do{
		puts("Choose column.");
		scanf("%d",&column);
		//system("clear");
		line = get_lowest_line(game, column, tetrimimo);
	}while (line == -1);
	for(int i=4; i>= 0; i--){
		for(int j = 0; j< 4; j++){
			if (tetrimimo[i][j] == '@'){
				game[line+(i-3)][column + j] = '@';
			}
		}
	}

				
}


int main(int argc, char **argv)
{
	char game[10][10];
	int playing=0;
	int verif=0;
	int c=0;
	
	int tetrimimo;
	int rotat_number_piece;;
	
	
	puts("------------------WELCOME-------------------------");
	
	puts("1 : PLAY\n\n2 : QUIT");
	
	do {
		verif=scanf("%d",&playing);
		while ((c = getchar()) != '\n' && c != EOF) { }
		
		
	}while( verif != 1 || playing <= 0 || playing >3 );
	
	if(playing==1){
		system("clear");
		puts("GAME");
	}
	
	create_game(game);
	display(game);
	
	
	
	srand(time(NULL));
	int a=1;
	while (a==1){
		tetrimimo=rand()%7;
	
		switch (tetrimimo){
			case 0:
				rotat_number_piece = display_rotation(PIECE_1);
				place_block(PIECE_1[rotat_number_piece],game);
				display(game);
				break;
			case 1:
				rotat_number_piece =display_rotation(PIECE_2);
				place_block(PIECE_2[rotat_number_piece],game);
				display(game);
				break;
			case 2:
				rotat_number_piece =display_rotation(PIECE_3);
				place_block(PIECE_3[rotat_number_piece],game);
				display(game);
				break;
			case 3:
				rotat_number_piece =display_rotation(PIECE_4);
				place_block(PIECE_4[rotat_number_piece],game);
				display(game);
				break;
			case 4:
				rotat_number_piece =display_rotation(PIECE_5);
				place_block(PIECE_5[rotat_number_piece],game);
				display(game);
				break;
			case 5:
				rotat_number_piece =display_rotation(PIECE_6);
				place_block(PIECE_6[rotat_number_piece],game);
				display(game);
				break;
			case 6:
				rotat_number_piece =display_rotation(PIECE_7);
				place_block(PIECE_7[rotat_number_piece],game);
				display(game);
				break;
			}
	}
	
	
	return 0;
}

