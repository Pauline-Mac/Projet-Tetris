#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TAILLE 10


int verif_ligne (char tab[][TAILLE], int ligne){
	for(int i=0;i<TAILLE;i++){
		if(tab[ligne][i]==' '){
			return 0;
		}
	}
	return 1;
}

void eraser(char tab[][TAILLE], int ligne){
	for(int i=0;i<TAILLE;i++){
		tab[ligne][i]=' ';
	}
}


void table_descent (char tab[][TAILLE], int ligne){
	for(int i=ligne;i>0;i--){
		for(int j=0;j<TAILLE;j++){
			tab[i][j]=tab[i-1][j];
		}
	}
	for(int j=0;j<TAILLE;j++){
		tab[0][j]=' ';	
	}
}

void affiche(char tab[][TAILLE]){
	for(int i=0;i<TAILLE;i++){
		for(int j=0;j<TAILLE;j++){
			printf("%c|", tab[i][j]);
		}
		puts("");
	}
}	

int main(){
	int verif=0;
	char tab[TAILLE][TAILLE];
	for(int i=0;i<TAILLE;i++){
		for(int j=0;j<TAILLE;j++){
			if (i==4)
				tab[i][j]='@';
			else if(j%2==0)
				tab[i][j]='@';
			else
				tab[i][j]=' ';
		}
		puts("");
	}
	affiche(tab);
	
	for (int i=0;i<TAILLE;i++){
		verif=verif_ligne(tab, i);
		printf("%d\n", verif);
		if(verif==1){
			eraser(tab, i);
			table_descent(tab, i);
		}
	}
	affiche(tab);
	
	return 0;
}
