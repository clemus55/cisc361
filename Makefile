all: MP3

MP3: MP3.o
	gcc MP3.o -o MP3
MP3.o: MP3.c MP3.h
	gcc -c MP3.c -o MP3.o
clean:
	rm *.o MP3
