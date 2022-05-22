#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	FILE* fp=NULL;
	fp=fopen("test.txt", "r+");
	int nbline = 0;
	char alias[100];
	int ScorePlayer = 12;
	puts("Entrer alias");
	scanf("%s",alias);
	/* adds \n between the last caractere of name and \0 caractere because
	 strcomp() also compares \n at end of line in result.txt*/
	alias[strlen(alias)] = '\n';
	alias[strlen(alias)+1] = '\0';
	char line[100];
	// check if username already exists
	while ( fgets(line,101,fp)!=NULL){
		nbline++;
		if (strcmp(line,alias) == 0){
			puts("WELCOME BACK");
		}
		
	}
	rewind(fp);
	// at end of game
	
	
	// check if first player
	if (nbline == 1){
		printf("you are the first player, new best score is: %d",ScorePlayer);
	}
	//if not first player checks for best score inside data base
	char username[100];
	char usernameScoreTab[100];
	int usernameScore = 0;
	int bestscore = 0;
	char BestScoreUsername[100];
	
	while ( fgets(username,101,fp)!=NULL && fgets(usernameScoreTab,101,fp)!=NULL){
		usernameScore = atoi(usernameScoreTab);
		printf("player: %s your score is : %d\n", username, usernameScore);
		// saves best score and best score username
		if ( usernameScore > bestscore){
			bestscore = usernameScore;
			strcpy(BestScoreUsername, username);
		}
	}
		
	printf("Le best score est: %d réalisé par %s\n", bestscore,BestScoreUsername);
	
	fclose(fp);


	return 0;
}	
