#include 'line_verif.h'




int verif_line (char tab[][10], int line){
	for(int i=0;i<10;i++){
		if(tab[line][i]=='_'){
			return 0;
		}
	}
	return 1;
}

void eraser(char tab[][10], int line){
	for(int i=0;i<10;i++){
		tab[line][i]='_';
	}
}


void table_descent (char tab[][10], int line){
	for(int i=line;i>0;i--){
		for(int j=0;j<10;j++){
			tab[i][j]=tab[i-1][j];
		}
	}
	for(int j=0;j<10;j++){
		tab[0][j]='_';	
	}
}

int check_line_for_score(char tab[10][10], int* scr){
	int verif = 0;
	for (int i=0;i<10;i++){
		verif=verif_line(tab, i);
		if(verif==1){
			*scr+=10;
			eraser(tab, i);
			table_descent(tab, i);
			return 1;
		}
	}
	return 0;
}
