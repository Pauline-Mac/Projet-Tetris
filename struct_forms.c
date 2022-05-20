#include <stdio.h>



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


#define PIECE1_INDEX 0
#define PIECE2_INDEX 4

//#define ROT0 0
//#define ROT90 1
//#define ROT180 2


/*create(&Piece, PIECE1_INDEX)
{
	copy &piece->rotat0  / index + ROT0
	copy &piece->rotat90  / index + ROT90
	
}*/

/*typedef struct {
	char rotat1[4][4];
	char rotat2[4][4];
	char rotat3[4][4];
	char rotat4[4][4];
}Piece;
*/

int main(){
	typedef enum {
		PIECE_1,PIECE_2,PIECE_3,PIECE_4,PIECE_5,PIECE_6,PIECE_7
	}PIECES;
	
	
	/*for (int i=0;i<7;i++){
		for(int h=0;h<4;h++){			
			for (int j=0;j<4;j++){
				// ptr vers struct         // indice de la matrice (piece + rotation)
				Tetrimo_i.rotat1[i][j] = PIECES[0][i][j];
				printf("%c |", Tetrimo_i.rotat1[i][j]);
				
		}
		puts("");
	}
}*/
	return 0;
}
	

