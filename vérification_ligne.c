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

int main(){
	int verif=0;
	for (int i=0;i<TAILLE;i++){
		verif=verif_ligne(tab, i);
		printf("%d\n", verif);
		if(verif==1)
			eraser(tab, i);
	}
	
	return 0;
}

