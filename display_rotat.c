#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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

int display_rotation(const char tab[][4][4]){
	for(int y=0; y<4;y++){
		printf("  %d   ",y);
		
		for (int i =0; i<4; i++){
			for(int j=0; j<4;j++){
				printf("%c ",tab[y][i][j]);
			}
			puts("");
		}
		puts("");
	}
	int rotat_number=-1;
	int verif=0;
	do {
		puts("Enter rotation number");
		verif=scanf("%d",&rotat_number);
		puts("After Scanf");
		int c;
		while ((c = getchar()) != '\n' && c != EOF) { }
		
		
	}while( verif != 1 || rotat_number < 0 || rotat_number >= 4);
	return rotat_number;
	
}

int main(int argc, char **argv)
{
	srand(time(NULL));
	int tetrimimo=rand()%7;
	int rotat_number_piece;
	
	switch (tetrimimo){
		case 0:
			rotat_number_piece = display_rotation(PIECE_1);

			
			break;
		case 1:
			display_rotation(PIECE_2);
			break;
		case 2:
			display_rotation(PIECE_3);
			break;
		case 3:
			display_rotation(PIECE_4);
			break;
		case 4:
			display_rotation(PIECE_5);
			break;
		case 5:
			display_rotation(PIECE_6);
			break;
		case 6:
			display_rotation(PIECE_7);
			break;
	}
	return 0;
}

