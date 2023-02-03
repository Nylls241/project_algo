

prog : main.o init.o dessin_rendu1.o input.o destroy.o
	gcc -o prog main.o init.o dessin_rendu1.o input.o destroy.o display_text.o `sdl2-config --cflags --libs` -lSDL2_ttf

main.o : src/main.c
	gcc -c -Wall src/main.c 

init.o : src/init.c
	gcc -c -Wall src/init.c 

dessin_rendu1.o : src/dessin_rendu1.c 
	gcc -c -Wall src/dessin_rendu1.c

input.o : src/input.c
	gcc -c -Wall src/input.c 

destroy.o : src/destroy.c
	gcc -c -Wall src/destroy.c

display_text.o : src/display_text.c
	gcc -c -Wall src/display_text.c 

clean :
	rm -f *.o

