#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include <string.h>




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

void get_alias(char alias[101], FILE* fp, int* nbline, int* updateScore){
	



	int input = 0;
	
	
	char line[101];



	while(input==0){
		puts("Enter alias  ( max 100 ) ");
		fgets ( alias, 101, stdin );
		
		
		//checks if input is not \n
		if (strcmp(alias,"\n") != 0){
			input = 1;
		}
	}
	
	
	
	// check if username already exists
	while ( fgets(line,101,fp)!=NULL){
		*(nbline)++;
		if (strcmp(line,alias) == 0 && *updateScore == 0){
			puts("WELCOME BACK");
			*updateScore = 1;
		}
		
	}
}




int display_rotation(const char tab[][4][4]){
	int rotat_number=-1;
	int verif=0;
	int c;
	long start;
	long end;
	
	// display every rotation
	puts("\n");
	puts("     0        1         2          3");
	for (int i=0; i<4; i++){
		for (int y=0; y<4; y++){
			printf("    ");
			for (int j=0; j<4;j++){
				printf("%c",tab[y][i][j]);
			}
			printf("   ");
		}
		puts("");
	}
	
	
	// gets correct rotation number
	puts("You have 5sec");
	start=time (NULL);
	do {
		puts("Enter rotation number");
		verif=scanf("%d",&rotat_number);
		while ((c = getchar()) != '\n' && c != EOF) { }
		
		
	}while( verif != 1 || rotat_number < 0 || rotat_number >= 4);
	end=time(NULL);
	
	if(end-start>5){
		rotat_number = rand()%4;
		puts("too slow!!");
		printf("Your rotation number is %d\n",rotat_number);
	}
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
	puts("                0 1 2 3 4 5 6 7 8 9");
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
					//end game
					
					return -1;
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
}


int get_lowest_line(char game[10][10], int column, const char tetrimo[4][4], int random){
	// This fonction return the index number of the lowest line that isn't already '@'
	// If column is alredy full it returns -1

	int ln =9;
	while(ln >=0){
		
		if (game[0][column] == '@'){
			return -2;
		}
		
		if ( check_room(game,column,ln,tetrimo) == -1){
			// end game
			return -2;
		}
		if ( check_room(game,column,ln,tetrimo) == 1){
			return ln;
		}
		else{
			ln--;
		}
	
	}
	if (random == 0){
		puts("You can not place your tetrimimo here");
	}
	return -1;
}



		
	

int place_block(const char tetrimimo[4][4], char game[10][10]){
	int column;int line=-1;int check;int ch;long start;long end;
	start=time (NULL);
	puts("You have 5sec :");
	do {
		puts("Choose column.");
		check=scanf("%d",&column);
		while ((ch = getchar()) != '\n' && ch != EOF) { }
		line = get_lowest_line(game, column, tetrimimo,0);
		if ( line == -2){
			return 0;
		}
		
	}while( line == -1 || check != 1 || column < 0 || column >= 10 );
	end=time (NULL);

	if(end-start>5){
		puts("too slow!!");
		do{
			column = rand()%10;
			line = get_lowest_line(game, column, tetrimimo,1);
		}while(line == -1);
		printf("Your column is %d\n",column);
		sleep(2);
	}
	
		

	for(int i=4; i>= 0; i--){
		for(int j = 0; j< 4; j++){
			if (tetrimimo[i][j] == '@'){
				game[line+(i-3)][column + j] = '@';
			}
		}
	}
	return 1;
				
}

int verif_line (char tab[][10], int line){
	for(int i=0;i<10;i++){
		if(tab[line][i]=='_'){
			return 0;
		}
	}
	return 1;
}

void eraser(char tab[][10], int line){
	for(int i=0;i<10;i++){
		tab[line][i]='_';
	}
}


void table_descent (char tab[][10], int line){
	for(int i=line;i>0;i--){
		for(int j=0;j<10;j++){
			tab[i][j]=tab[i-1][j];
		}
	}
	for(int j=0;j<10;j++){
		tab[0][j]='_';	
	}
}

int check_line_for_score(char tab[10][10], int* scr){
	int verif = 0;
	for (int i=0;i<10;i++){
		verif=verif_line(tab, i);
		if(verif==1){
			*scr+=10;
			eraser(tab, i);
			table_descent(tab, i);
			return 1;
		}
	}
	return 0;
}

void end_game_score(char alias[101], int* ScorePlayer,FILE* fp, int* updateScore, int* nbline){
	
	
	char line[101];
	char oldScoreTab[101];
	int oldScore;
	char username[100];
	char usernameScoreTab[100];
	int usernameScore = 0;
	int bestscore = 0;
	char BestScoreUsername[100];
	
	
	// at end of game
	if (*nbline == 1){
		fseek(fp, 0, SEEK_SET);
	}
	if (*updateScore !=1){
		fprintf(fp, "%s", alias);
		fprintf(fp, "%d\n", *ScorePlayer);
	}
	else{
		fseek(fp, 0, SEEK_SET);
		while ( fgets(line,101,fp)!=NULL){
			
			if (strcmp(line,alias) == 0){
				
				fgets(oldScoreTab,101,fp);
				oldScore = atoi(oldScoreTab);
				
				if ( *ScorePlayer > oldScore){
					fseek(fp, -strlen(oldScoreTab), SEEK_CUR);
					fprintf(fp, "%d\n", *ScorePlayer);
				}
			}
		}
		
	}
	
	rewind(fp);
	
	// check if first player
	if (*nbline == 1){
		printf("you are the first player, new best score is: %d",*ScorePlayer);
	}
	//if not first player checks for best score inside data base
	
	
	
	while ( fgets(username,101,fp)!=NULL && fgets(usernameScoreTab,101,fp)!=NULL){
		usernameScore = atoi(usernameScoreTab);
		printf("player: %s your score is : %d\n", username, usernameScore);
		// saves best score and best score username
		if ( usernameScore >= bestscore){
			bestscore = usernameScore;
			strcpy(BestScoreUsername, username);
		}
	}
		
	printf("The best score is: %d scored by %s\n", bestscore,BestScoreUsername);
	
	fclose(fp);
	sleep(3);
	exit(0);
}


void end_game(){
	system("clear");
	puts("                 Your block exceeded the grid");
	sleep (3);
	puts("     _____          __  __ ______    ______      ________ _____ ");
	puts("    / ____|   /\\   |  \\/  |  ____|  / __ \\ \\    / /  ____|  __ \\ ");
	puts("   | |  __   /  \\  | \\  / | |__    | |  | \\ \\  / /| |__  | |__) |");
	puts("   | | |_ | / /\\ \\ | |\\/| |  __|   | |  | |\\ \\/ / |  __| |  _  /");
	puts("   | |__| |/ ____ \\| |  | | |____  | |__| | \\  /  | |____| | \\ \\");
	puts("    \\_____/_/    \\_\\_|  |_|______|  \\____/   \\/   |______|_|  \\_\\");
	sleep(3);
	
}



int main(int argc, char **argv)
{
	char name[101];
	FILE* file=NULL;
	file=fopen("score_data.txt", "a+");
	int score = 0;
	int* pscore = &score;
	int updateScore = 0;
	int* pupdateScore = &updateScore;
	int nbline = 0;
	int* pnbline = &nbline;
	
	
	get_alias(name,file, pnbline,pupdateScore);
	
	
	
	char game[10][10];
	int playing=0;
	int verif=0;
	int c=0;
	
	int tetrimimo;
	int rotat_number_piece;
	
	
	
	puts("------------------WELCOME-------------------------");
	
	puts("1 : PLAY\n\n2 : QUIT");
	
	do {
		verif=scanf("%d",&playing);
		while ((c = getchar()) != '\n' && c != EOF) { }
		
		
	}while( verif != 1 || playing <= 0 || playing >3 );
	
	if(playing==1){
		system("clear");
	}
	
	create_game(game);
	display(game);
	
	
	srand(time(NULL));
	while (playing==1){
		
		tetrimimo=rand()%7;
		
	
		switch (tetrimimo){
			case 0:
				rotat_number_piece = display_rotation(PIECE_1);
				if (place_block(PIECE_1[rotat_number_piece],game) == 1){
					display(game);
					if (check_line_for_score(game,&score)==1){
						sleep(1);
						system("clear");
						display(game);
					}
				}
				else {
					end_game();
					end_game_score(name,pscore,file, pupdateScore, pnbline);
					playing = 0;
				}
				break;
			case 1:
				rotat_number_piece =display_rotation(PIECE_2);
				if (place_block(PIECE_2[rotat_number_piece],game)==1){
					display(game);
					if (check_line_for_score(game,&score)==1){
						sleep(1);
						system("clear");
						display(game);
					}
				}
				else {
					end_game();
					end_game_score(name,pscore,file, pupdateScore, pnbline);
					playing = 0;
				}
				break;
			case 2:
				rotat_number_piece =display_rotation(PIECE_3);
				if (place_block(PIECE_3[rotat_number_piece],game)==1){
					display(game);
					if (check_line_for_score(game,&score)==1){
						sleep(1);
						system("clear");
						display(game);
					}
				}
				else {
					end_game();
					end_game_score(name,pscore,file, pupdateScore, pnbline);
					playing = 0;
				}
				break;
			case 3:
				rotat_number_piece =display_rotation(PIECE_4);
				if (place_block(PIECE_4[rotat_number_piece],game)==1){
					display(game);
					if (check_line_for_score(game,&score)==1){
						sleep(1);
						system("clear");
						display(game);
					}
				}
				else {
					end_game();
					end_game_score(name,pscore,file, pupdateScore, pnbline);
					playing = 0;
				}
				break;
			case 4:
				rotat_number_piece =display_rotation(PIECE_5);
				if (place_block(PIECE_5[rotat_number_piece],game)==1){
					display(game);
					if (check_line_for_score(game,&score)==1){
						sleep(1);
						system("clear");
						display(game);
					}
				}
				else {
					end_game();
					end_game_score(name,pscore,file, pupdateScore, pnbline);
					playing = 0;
				}
				break;
			case 5:
				rotat_number_piece =display_rotation(PIECE_6);
				if (place_block(PIECE_6[rotat_number_piece],game)==1){
					display(game);
					if (check_line_for_score(game,&score)==1){
						sleep(1);
						system("clear");
						display(game);
					}
				}
				else {
					end_game();
					end_game_score(name,pscore,file, pupdateScore, pnbline);
					playing = 0;
				}
				break;
			case 6:
				rotat_number_piece =display_rotation(PIECE_7);
				if (place_block(PIECE_7[rotat_number_piece],game)==1){
					display(game);
					if (check_line_for_score(game,&score)==1){
						system("clear");
						sleep(1);
						display(game);
					}
				}
				else {
					end_game();
					end_game_score(name,pscore,file, pupdateScore, pnbline);
					playing = 0;
				}
				break;
			}
	}
	
	
	return 0;
}
