#include "display.h"






int display_rotation(const char tab[][4][4]){
	int rotat_number=-1;
	int verif=0;
	int c;
	long start;
	long end;
	
	// display every rotation
	puts("\n");
	puts("     0        1         2          3");
	for (int i=0; i<4; i++){
		for (int y=0; y<4; y++){
			printf("    ");
			for (int j=0; j<4;j++){
				printf("%c",tab[y][i][j]);
			}
			printf("   ");
		}
		puts("");
	}
	
	
	// gets correct rotation number
	puts("You have 5sec");
	start=time (NULL);
	do {
		puts("Enter rotation number");
		verif=scanf("%d",&rotat_number);
		while ((c = getchar()) != '\n' && c != EOF) { }
		
		
	}while( verif != 1 || rotat_number < 0 || rotat_number >= 4);
	
	//timer
	end=time(NULL);
	
	if(end-start>5){
		rotat_number = rand()%4;
		puts("too slow!!");
		printf("Your rotation number is %d\n",rotat_number);
	}
	return rotat_number;
	
}



/*_________This fonction display tetris logo and game grid_______*/
void display(char tab[10][10]){
	
	puts("    __ _______         __         __         __   ");
	puts("  ,' _|_     _|.-----.|  |_.----.|__|.-----.|_ `. ");
	puts(" /  /   |   |  |  -__||   _|   _||  ||__ --|  \\  \\ ");
	puts(" \\  \\_  |___|  |_____||____|__|  |__||_____| _/  / ");
	puts("  `.__|                                     |__,' ");
	puts("");
	puts("                0 1 2 3 4 5 6 7 8 9");
	puts("");
	
	for (int i=0; i<10; i++){
		printf("               |");
		for(int j=0; j<10; j++){
			printf("%c", tab[i][j]);
			printf("|");
		}
		puts("");
	}
}

/*_______display game over_______*/
void end_game(){
	system("clear");
	puts("                 Your block exceeded the grid");
	sleep (3);
	puts("     _____          __  __ ______    ______      ________ _____ ");
	puts("    / ____|   /\\   |  \\/  |  ____|  / __ \\ \\    / /  ____|  __ \\ ");
	puts("   | |  __   /  \\  | \\  / | |__    | |  | \\ \\  / /| |__  | |__) |");
	puts("   | | |_ | / /\\ \\ | |\\/| |  __|   | |  | |\\ \\/ / |  __| |  _  /");
	puts("   | |__| |/ ____ \\| |  | | |____  | |__| | \\  /  | |____| | \\ \\");
	puts("    \\_____/_/    \\_\\_|  |_|______|  \\____/   \\/   |______|_|  \\_\\");
	sleep(3);
	
}

