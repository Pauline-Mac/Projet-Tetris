#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	int choice=0;
	int verif=0;
	int c=0;
	puts("    __ _______         __         __         __   ");
	puts("  ,' _|_     _|.-----.|  |_.----.|__|.-----.|_ `. ");
	puts(" /  /   |   |  |  -__||   _|   _||  ||__ --|  \\  \\ ");
	puts(" \\  \\_  |___|  |_____||____|__|  |__||_____| _/  / ");
	puts("  `.__|                                     |__,' ");
	puts("");
	
	puts("------------------WELCOME-------------------------");
	
	puts("1 : PLAY\n\n2 : QUIT");
	
	do {
		verif=scanf("%d",&choice);
		while ((c = getchar()) != '\n' && c != EOF) { }
		
		
	}while( verif != 1 || choice <= 0 || choice >3 );
	
	if(choice==1){
		system("clear");
		puts("GAME");
	}
	else{
		return 1;
	}
	return 0;
}

