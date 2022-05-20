#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void verif_pointeur_c(char* pointe){
	if(pointe==NULL){
		exit(1);
	}
}

void verif_pointeur_float(float* pointe){
	if(pointe==NULL){
		exit(1);
	}
}

void verif_pointeur_int(int* pointe){
	if(pointe==NULL){
		exit(1);
	}
}

// checking if it is a caracter string

int verif_string(char string[], int size){
	verif_pointeur_c(string);
	for(int i=0;i<size;i++){
		if(string[i]<'A'){
			return 0;
		}
		else if (string[i]>'Z'){
			if(string[i]<'a'){
				return 0;
			}
			else if(string[i]>'z'){
				return 0;
			}
		}
	}
	return 1;
}


char* input(char alias[], int* size){
	char* aux=NULL; // creation of a pointer that will be used for dynamic allocation
	//loop to be sure to have a string of letters
	do{
	puts("please enter your alias");
	scanf("%s",alias);
	*size=strlen(alias); 
	}while(verif_string(alias, *size)!=1);
	aux=malloc(*size*sizeof(char)); // dynamic allocation thanks to the recovered size
	
	// copy the string into the table at the corresponding size
	
	for(int i=0;i<*size;i++){
		aux[i]=alias[i];
	}
	return aux;
}

int main(){
	FILE* fp=NULL;
	int size=0;
	int* psize=&size;
	char input_alias[400];
	fp=fopen("result_saving.txt", "a+");
	char* alias=input(input_alias,psize);
	fprintf(fp,"%s\n", alias);
	fclose(fp);
	free(alias);
	return 0;
}
	
	
	
