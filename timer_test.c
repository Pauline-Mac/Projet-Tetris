#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

int input(int g){
	char c;
	char* pc=&c;
	c=fgetc(stdin);
	//checks if input is not \n
	if (strcmp(pc,"\n") != 0){
		g = atoi(pc);
	}
	return g;

}

int main ()
{
	int g=-1;
   time_t ta;
   time_t tb;

   time (&ta);
	
	printf("%ld\n", ta);
	
	tb=ta;
	while(tb-ta<10 && g==-1){
		sleep(1);
		time(&tb);

		printf("%ld\n", tb-ta);	
		g=input(g);
	}
	if(tb-ta>10){
		puts("too slow !!!!!!");
	}
	else
		printf("%d", g);
	
   return 0;
}

