#include 'positioning.h'



void create_game(char GameGrid[][10]){

	for (int i = 0; i<10; i++){
		for(int j=0; j<10; j++){
			GameGrid[i][j] = '_';
		}
	}
}


int check_room(char game[10][10], int column, int line, const char tetrimo[4][4]){
	// check if there is room for the whole tetrimimo
	// return 1 if there is enough place, 0 if not
	int place=1;
	if (place==1){
		for (int i =4; i>=0; i--){
			for (int j= 0; j< 4 ;j++){
				if (line+(i-3) < 0 && tetrimo[i][j] == '@'){
					//end game
					
					return -1;
				}
				if ( column + j > 9 && tetrimo[i][j] == '@'){
				
					return 0;
				}
				else if (tetrimo[i][j] == '@' && game[line+(i-3)][column + j] == '@'){
					return 0;
				}
			}
		}
	}

	return place;
}


int get_lowest_line(char game[10][10], int column, const char tetrimo[4][4], int random){
	// This fonction return the index number of the lowest line that isn't already '@'
	// If column is alredy full it returns -1

	int ln =9;
	while(ln >=0){
		
		if (game[0][column] == '@'){
			return -2;
		}
		
		if ( check_room(game,column,ln,tetrimo) == -1){
			// end game
			return -2;
		}
		if ( check_room(game,column,ln,tetrimo) == 1){
			return ln;
		}
		else{
			ln--;
		}
	
	}
	if (random == 0){
		puts("You can not place your tetrimimo here");
	}
	return -1;
}



		
	

int place_block(const char tetrimimo[4][4], char game[10][10]){
	int column;int line=-1;int check;int ch;long start;long end;
	start=time (NULL);
	puts("You have 5sec :");
	do {
		puts("Choose column.");
		check=scanf("%d",&column);
		while ((ch = getchar()) != '\n' && ch != EOF) { }
		line = get_lowest_line(game, column, tetrimimo,0);
		if ( line == -2){
			return 0;
		}
		
	}while( line == -1 || check != 1 || column < 0 || column >= 10 );
	end=time (NULL);

	if(end-start>5){
		puts("too slow!!");
		do{
			column = rand()%10;
			line = get_lowest_line(game, column, tetrimimo,1);
		}while(line == -1);
		printf("Your column is %d\n",column);
		sleep(2);
	}
	
		

	for(int i=4; i>= 0; i--){
		for(int j = 0; j< 4; j++){
			if (tetrimimo[i][j] == '@'){
				game[line+(i-3)][column + j] = '@';
			}
		}
	}
	return 1;
				
}
