SDL = `sdl2-config --cflags --libs`
COMPIL = gcc -Wall -pedantic -g -lm $(SDL) 

#####################################################################

main:
	$(COMPIL) main.c -o main
	
clean:
	rm -f main
	
#####################################################################
