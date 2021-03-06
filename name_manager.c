#include "name_manager.h"


// ask for player name and check if already in data base
void get_alias(char alias[101], FILE* fp, int* nbline, int* updateScore){
	
	int input = 0;
	
	char line[101];



	while(input==0){
		puts("Enter alias  ( max 100 ) ");
		fgets ( alias, 101, stdin );
		
		
		//checks if input is not \n
		if (strcmp(alias,"\n") != 0){
			input = 1;
		}
	}
	
	
	
	// check if username already exists
	while ( fgets(line,101,fp)!=NULL){
		*(nbline)++;
		if (strcmp(line,alias) == 0 && *updateScore == 0){
			puts("WELCOME BACK");
			*updateScore = 1;
		}
		
	}
}

// show best score and add final score to data base
void end_game_score(char alias[101], int* ScorePlayer,FILE* fp, int* updateScore, int* nbline){
	
	
	char line[101];
	char oldScoreTab[101];
	int oldScore;
	char username[100];
	char usernameScoreTab[100];
	int usernameScore = 0;
	int bestscore = 0;
	char BestScoreUsername[100];
	
	
	/* UPDATE SCORE OR ADD PLAYER NAME AND FINAL SCORE TO DATA BASE*/
	
	// at end of game
	if (*nbline == 1){
		fseek(fp, 0, SEEK_SET);
	}
	
	if (*updateScore !=1){
		fprintf(fp, "%s", alias);
		fprintf(fp, "%d\n", *ScorePlayer);
	}
	// update old score if inferior to new score
	else{
		fseek(fp, 0, SEEK_SET);
		while ( fgets(line,101,fp)!=NULL){
			
			if (strcmp(line,alias) == 0){
				
				fgets(oldScoreTab,101,fp);
				oldScore = atoi(oldScoreTab);
				
				if ( *ScorePlayer > oldScore){
					fseek(fp, -strlen(oldScoreTab), SEEK_CUR);
					fprintf(fp, "%d\n", *ScorePlayer);
				}
			}
		}
		
	}
	
	rewind(fp);
	
	/* SHOW BEST SCORE*/
	
	// check if first player
	if (*nbline == 1){
		printf("you are the first player, new best score is: %d",*ScorePlayer);
	}
	//if not first player checks for best score inside data base
	
	while ( fgets(username,101,fp)!=NULL && fgets(usernameScoreTab,101,fp)!=NULL){
		usernameScore = atoi(usernameScoreTab);
		printf("player: %s your score is : %d\n", username, usernameScore);
		// saves best score and best score username
		if ( usernameScore >= bestscore){
			bestscore = usernameScore;
			strcpy(BestScoreUsername, username);
		}
	}
		
	printf("The best score is: %d scored by %s\n", bestscore,BestScoreUsername);
	
	fclose(fp);
	sleep(3);
	exit(0);
}
