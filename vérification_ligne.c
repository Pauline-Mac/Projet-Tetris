#include <stdio.h>

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


void descente_tab(char tab[][TAILLE]){
	int j=TAILLE-1;
	while(j>0){
		for(int i=0;i<TAILLE;i++){
			tab[j][i]=tab[j-1][i];
		}
		j--;
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
			tab[i][j]='@';
		}
		puts("");
	}
	affiche(tab);
	
	for (int i=0;i<TAILLE;i++){
		verif=verif_ligne(tab, i);
		printf("%d\n", verif);
		if(verif==1)
			eraser(tab, i);
	}
	affiche(tab);
	
	return 0;
}
