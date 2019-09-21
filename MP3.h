#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct MP3* GetNewSong(char* artist, char* songTitle,int songMade, int run);

void add_list(char* artist, char* songTitle,int songMade, int run);

void printFor();
void printBack();
void deleteSong();
void deleteNode(struct MP3 *del);
