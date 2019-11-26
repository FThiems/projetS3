SDL = `sdl2-config --cflags --libs`
COMPILE = gcc -Wall -pedantic -g -lm 
DEFH = $(LIBH)definitions.h 
NAME = game

#folders
LIB=library/
LIBH=library/headers/

#sources
SRC = $(LIB)initialisation.o $(LIB)events.o $(LIB)data.o $(LIB)graphics.o

#headers
HEAD = $(LIBH)definitions.h $(LIBH)initialisation.h $(LIBH)events.h $(LIBH)data.h $(LIBH)graphics.h

#####################################################################
#gcc -Wall -g $(SRC) -lm `sdl-config --cflags --libs` -o $(BIN)

game: main.c $(SRC) $(HEAD)
	$(COMPILE) $(SRC) main.c -o $(NAME) $(SDL) 
	
#####################################################################

initialisation.o:  $(LIB)initialisation.c            $(LIBH)initialisation.h             $(DEFH)  
	$(COMPILE)    -c initialisation.c                -o initialisation.o

events.o:          $(LIB)events.c                    $(LIBH)events.h                     $(DEFH)
	$(COMPILE)    -c events.c                        -o events.o

data.o:            $(LIB)data.c                      $(LIBH)data.h                       $(DEFH)
	$(COMPILE)    -c data.c                          -o data.o              

graphics.o:        $(LIB)graphics.c                  $(LIBH)graphics.h                   $(DEFH)
	$(COMPILE)	  -c graphics.c 					 -o graphics.o                    

#####################################################################

clean:
	rm -f $(NAME)

superclean:
	rm -f $(SRC) $(NAME) 
	
#####################################################################
