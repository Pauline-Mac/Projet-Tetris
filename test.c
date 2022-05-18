#include <stdio.h>
#include <stdlib.h>

void place_block(char tetrimimo[4][4], char game[10][10], int lowest_block_x, int lowest_block_y){
	int colomn;
	puts("Choose colomn.");
	scanf("%d",&colomn);
	system("clear");
	
	printf("colomn scanned  value: %d", colomn);
	// 1 tetrimimo is only composed of 4 blocks
	int line = 9;
	if(line!=-1){
		for(int i=4; i> 0; i--){
			for(int j = 0; j< 4; j++){
				if (tetrimimo[i][j] == '@'){
					game[line+(i-3)][colomn + j] = '@';
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
	
	
	for (int i=0; i<10; i++){
		printf("|");
		for(int j=0; j<10; j++){
			printf("%c", game[i][j]);
			printf("|");
		}
		puts("");
	}
	
	char cube[4][4] = {{'_','_','_','_'},{'_','_','_','_'},{'@','@','_','_'},{'@','@','_','_'}};
	
	place_block(cube, game, 1, 3);
	
	
	/*for(int i=4; i> 0; i--){
			for(int j = 0; j< 4; j++){
				if (cube[i][j] == '@'){
					game[9 + (i-3)][2 + j] = '@';
				}
			}
	}*/
	
	
	//system("clear");
	puts("nouvel essai");
	
	
	for (int i=0; i<10; i++){
		printf("|");
		for(int j=0; j<10; j++){
			printf("%c", game[i][j]);
			printf("|");
		}
		puts("");
	}
		
	
		
	
	return 0;
}

