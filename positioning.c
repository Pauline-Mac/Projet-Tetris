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
	for (int i =0; i< 4; i++){
		if( (game[line][colomn+i]!='_') || (tetrimo[lowest_block_x][lowest_block_y+i])){
			int a =10;
		}
	}
}


int get_lowest_line(char game[10][10], int colomn, char tetrimo[4][4], int lowest_block_x, int lowest_block_y){
	// This fonction return the index number of the lowest line that isn't already '@'
	// If colomn is alredy full it returns -1
	int check = 0;
	int ln =10;
	int i = 1;
	while(i > 0){
		if( game[ln][colomn] == '_'){
			check_room(game,colomn,ln,tetrimo[4][4], lowest_block_x, lowest_block_y);
			return ln;
		}
		else {
			ln++;
		}
	}
	puts("Colomn already full");
	return -1;
}



		
	

void place_block(char tetrimimo[4][4], int colomn, char game[10][10], int lowest_block_x, int lowest_block_y){
	puts("Choose colomn.");
	scanf("%d",&colomn);
	// 1 tetrimimo is only composed of 4 blocks
	int line;
	int i =1;
	for (int block =0; block < 4 ;block++){
		do{
			line = get_lowest_line(game, colomn + lowest_block_y, tetrimimo, lowest_block_x,lowest_block_y);
			
			if (line != -1 ){
				int a = 10;
			}
		}while (i==0);
			
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
	return 0;
}	
