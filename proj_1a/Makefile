MP3: MP3.o
	gcc -g MP3.o -o MP3
MP3.o: MP3.c MP3.h
	gcc -c -g MP3.c
clean:
	rm MP3.o MP3
run: MP3
	./MP3

test: MP3
	valgrind --leak-check=full --track-origins=yes -v ./mp3
