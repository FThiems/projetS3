#`sdl2-config --cflags --libs`

SDL = `sdl2-config --cflags --libs`
COMPIL = gcc -Wall -pedantic -g -lm 

#####################################################################

main:
	$(COMPIL) main.c -o main $(SDL) 
	
clean:
	rm -f main
	
#####################################################################
