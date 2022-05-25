#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	FILE* fp=NULL;
	fp=fopen("test.txt", "a+");
	int nbline = 0;
	char alias[101];
	int ScorePlayer = 15;
	int input = 0;
	int updateScore = 0;
	char oldScoreTab[101];
	int oldScore;
	char username[100];
	char usernameScoreTab[100];
	int usernameScore = 0;
	int bestscore = 0;
	char BestScoreUsername[100];


	while(input==0){
		puts("Entrer alias  ( max 100 ) ");
		fgets ( alias, 101, stdin );
		
		//checks if input is not \n
		if (strcmp(alias,"\n") != 0){
			input = 1;
		}
	}
	
	char line[101];
	
	// check if username already exists
	while ( fgets(line,101,fp)!=NULL){
		nbline++;
		if (strcmp(line,alias) == 0 && updateScore == 0){
			puts("WELCOME BACK");
			updateScore = 1;
		}
		
	}
	
	
	// at end of game
	if (nbline == 1){
		fseek(fp, 0, SEEK_SET);
	}
	if (updateScore !=1){
		fprintf(fp, "%s", alias);
		fprintf(fp, "%d\n", ScorePlayer);
	}
	else{
		fseek(fp, 0, SEEK_SET);
		while ( fgets(line,101,fp)!=NULL){
			
			if (strcmp(line,alias) == 0){
				
				fgets(oldScoreTab,101,fp);
				oldScore = atoi(oldScoreTab);
				
				if ( ScorePlayer > oldScore){
					fseek(fp, -strlen(oldScoreTab), SEEK_CUR);
					fprintf(fp, "%d\n", ScorePlayer);
				}
			}
		}
		
	}
	
	rewind(fp);
	
	// check if first player
	if (nbline == 1){
		printf("you are the first player, new best score is: %d",ScorePlayer);
	}
	//if not first player checks for best score inside data base
	
	
	
	while ( fgets(username,101,fp)!=NULL && fgets(usernameScoreTab,101,fp)!=NULL){
		usernameScore = atoi(usernameScoreTab);
		printf("player: %s your score is : %d\n", username, usernameScore);
		// saves best score and best score username
		if ( usernameScore > bestscore){
			bestscore = usernameScore;
			strcpy(BestScoreUsername, username);
		}
	}
		
	printf("The best score is: %d scored by %s\n", bestscore,BestScoreUsername);
	
	fclose(fp);


	return 0;
}	

