#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>


int main ()
{
	int g=0;
	long start;
	long end;
	char c;
	char* pc=&c;
	start=time (NULL);
	do{
	c=fgetc(stdin);
	//checks if input is not \n
	if (strcmp(pc,"\n") != 0){
		g=1;
	}
	}while(g==0);
	end=time(NULL);;
	
	if(end-start>5){
		printf("%ld\n", end-start);
		puts("too slow!!");
	}
	else{
		printf("%c\n", c);
		printf("%ld", end-start);
	}
		
   return 0;
}


