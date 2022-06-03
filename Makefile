# This is our makefile

all : exec

main.o : main.c display.h line_verif.h name_manager.h positioning.h
	gcc -c main.c -o main.o

display.o : display.c display.h
	gcc -c $< -o $@
	

line_verif.o : line_verif.c line_verif.h
	gcc -c $< -o $@

name_manager.o : name_manager.c name_manager.h
	gcc -c $< -o $@

positioning.o : positioning.c positioning.h
	gcc -c $< -o $@

exec : main.o display.o line_verif.o name_manager.o positioning.o 
	gcc main.o display.o line_verif.o name_manager.o positioning.o -o exec
	
clear : rm -f *.o
		rm exec
