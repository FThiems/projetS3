SDL = `sdl2-config --cflags --libs`
COMPIL = gcc -Wall -pedantic -g main.c -lm $(SDL) -o main

#####################################################################

main:
	$(COMPIL)
	
clean:
	rm -f main
	
#####################################################################
