exe: main.o niveau.o deplacement.o ../1/libisentlib.a 
	gcc -Wall main.o niveau.o deplacement.o -o exe ../1/libisentlib.a -lm -lglut -lGL -lX11
	
main.o: main.c header.h ../1/GfxLib.h ../1/BmpLib.h ../1/ESLib.h 
	gcc -Wall -c main.c -o main.o
		
niveau.o: niveau.c header.h ../1/GfxLib.h ../1/BmpLib.h ../1/ESLib.h 
	gcc -Wall -c niveau.c -o niveau.o

deplacement.o: deplacement.c header.h	../1/GfxLib.h ../1/BmpLib.h ../1/ESLib.h
	gcc -Wall -c deplacement.c -o deplacement.o
