

#include "display.h"

#include "line_verif.h"
#include "name_manager.h"
#include "positioning.h"


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
