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

int get_lowest_line(char game[10][10], int colomn){
	// This fonction return the index number of the lowest line that isn't already '@'
	// If colomn is alredy full it returns -1
	int i =10
	while(i > 0){
		if( game[i][colomn] == '_'){
			return i;
		else {
			i++;
		}
	}
	puts("Colomn already full");
	return -1;
}

void place_block(char tetrimimo[4][4], int colomn, char game[10][10]){
	puts("Choose colomn.");
	scanf("%d",&colomn);
	// on place seulement 4 petits blocks à l'interieur d'un tetrimo
	int line;
	for (int block =0; block < 4 ;block++){
		do{
			line = get_lowest_line(game, colomn);
			if (line != -1 ){
				game[line][colomn] = tetrimimo
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
