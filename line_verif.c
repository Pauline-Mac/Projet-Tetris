#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 10


int verif_line (char tab[][SIZE], int line){
	for(int i=0;i<SIZE;i++){
		if(tab[line][i]=='_'){
			return 0;
		}
	}
	return 1;
}

void eraser(char tab[][SIZE], int line){
	for(int i=0;i<SIZE;i++){
		tab[line][i]='_';
	}
}


void table_descent (char tab[][SIZE], int line){
	for(int i=line;i>0;i--){
		for(int j=0;j<SIZE;j++){
			tab[i][j]=tab[i-1][j];
		}
	}
	for(int j=0;j<SIZE;j++){
		tab[0][j]='_';	
	}
}

void display_tab(char tab[][SIZE]){
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
			printf("%c|", tab[i][j]);
		}
		puts("");
	}
}	

int main(){
	int verif=0;
	int score=0;
	char tab[SIZE][SIZE];
	//tab with full line
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
			if (i==4)
				tab[i][j]='@';
			else if(j%2==0)
				tab[i][j]='@';
			else
				tab[i][j]='_';
		}
		puts("");
	}
	display_tab(tab);
	// verification if full line
	for (int i=0;i<SIZE;i++){
		verif=verif_line(tab, i);
		printf("%d\n", verif);
		if(verif==1){
			score+=10;
			eraser(tab, i);
			table_descent(tab, i);
		}
	}
	display_tab(tab);
	puts("");
	
	

	return 0;
}
