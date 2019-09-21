#include <stdio.h>
#include <stdlib.h>
#include "MP3.h"
#define BUFFER 128

typedef struct MP3 {
   char* artist_name;
   char* title;
   int year;
   int runTime;

	
   struct MP3 *next;
   struct MP3 *prev;
}node;
struct MP3* head=NULL;
struct MP3* tail=NULL;

//GetNewSong: takes in a char*, char*, int and int
// returns a struct of type MP3
//The function creates a new MP3
struct MP3* GetNewSong(char* artist, char* songTitle,int songMade, int run) {
	int len;
	int len2;
	struct MP3* newSong = (struct MP3*)malloc(sizeof(struct MP3));
	 len = (int) strlen(artist);
	 artist[len-1]= '\0';
	 newSong->artist_name= (char *) malloc(len);
	 strcpy(newSong->artist_name, artist);        

	len2 = (int) strlen(songTitle); 
         songTitle[len-1]= '\0';
         newSong->title= (char *) malloc(len2);
	strcpy(newSong->title, songTitle);

 	 newSong->year = songMade;

 	 newSong->runTime = run;
	newSong->prev = NULL;
	newSong->next = NULL;
	
	return newSong;
}

//add_list: takes in a char*, char*, int, and int
//it returns nothing
//function adds new MP3 into DLL
void add_list(char* artist, char* songTitle,int songMade, int run){
 	 struct MP3* temp = head;
	struct MP3* newSong = GetNewSong(artist, songTitle, songMade, run);
	if(head == NULL) {
		head = newSong;
		tail= newSong;
		return;
	}
	else{ 
	  tail->next = newSong; 
		newSong->prev = tail;
	tail = newSong;
}
}

//printFor: takes in nothing
//returns nothing
//function prints out all elements of all the MP3's in the DLL, in the order it was added.
void printFor() {
	struct MP3* temp = head;
	while(temp != NULL) {
		printf("Artist Name: "); 
		printf("%s\n ",temp->artist_name);
		printf("Title Name: ");
		printf("%s\n ",temp->title);
		printf("Song Year: ");
		printf("%d\n ",temp->year);
		printf("Song's RunTime: ");
		printf("%d\n ",temp->runTime);
		temp = temp->next;
				}}	
//printBack: takes in nothing
//returns nothing
//function prints out all elements of all the MP3's in the DLL, in reverse order.
void printBack() {
	struct MP3* temp = tail;

	while(temp != NULL) {
	  printf("Artist Name: "); 
	  printf("%s\n ",temp->artist_name);
	  printf("Title Name: ");
	  printf("%s\n ",temp->title);
	  printf("Song Year: ");
	  printf("%d\n",temp->year);
	  printf("Song's RunTime: ");
	  printf("%d\n ",temp->runTime);
		temp = temp->prev;
	}	
}

//deleteNode: takes in a struct of type MP3
//returns nothing
//function deletes a node in MP3 DLL
void deleteNode(struct MP3 *deleted){
	free(deleted->artist_name);
	free(deleted->title);
	free(deleted);
}

//deleteSong(): takes in nothing
//returns nothing
//functions deletes all MP3's of the user inputted artist name
void deleteSong() 
{ 	struct MP3 *cur = head;
	struct MP3 *next;
 	int len;
        char *del;
	char artist2[BUFFER];

	if(head == NULL){
		return;		
	}

	if(fgets(artist2,BUFFER, stdin) != NULL){
                        len= (int)strlen(artist2);
                        artist2[len-1]='\0';
                        del = (char *)malloc(len);
                        strcpy(del, artist2);}

	while(cur != NULL){
		if(strcmp(cur->artist_name, del)== 0 ){
			next = cur->next;
			deleteNode(cur);
			cur = next;}

		else{
			cur = cur->next;}
		//	free(del);
}
			free(del);
}

int main() { 

	char title1[BUFFER];
	char artist1[BUFFER];
	char artist2[BUFFER];
    int yearMade;
    int runtime;
    int choice=1;

  //A main menu for options 
    while(choice != 0)
    {
        printf("============================================\n");
        printf("Music Library\n");
        printf("============================================\n");
        printf("1. Insert a Song\n");
        printf("2. Delete a Song\n");
        printf("3. Print Song List Forward\n");
        printf("4. Print Song List Backwards\n");
        printf("0. Exit Program\n");
        printf("--------------------------------------------\n");
        printf("Enter your choice : ");

        scanf("%d%*c", &choice);

        /*
         different menu options
         */
        switch(choice)
        {
            case 1:
            
                printf("Type in Artist Name: ");
               fgets(artist1, BUFFER, stdin);

                printf("Type in Title Name: ");
                 fgets(title1, BUFFER, stdin);
  
                printf("Type in Song's Year: ");
		scanf("%d",&yearMade);

                printf("Type in Runtime of Song: ");
		scanf("%d", &runtime);

                add_list(artist1,title1,yearMade,runtime);
	 
                break;
            case 2:
               printf("Type in Artist Name: ");
		deleteSong();
		break;
            case 3:
               printFor();
               break; 
            case 4:
              printBack();
              break;   
            case 0:
                break;
            default:
                printf("Please choose between 0-4");
        }

    }
	//freeing operation
	struct MP3 *temp = head;
	while(temp){
		free(temp->artist_name);
		free(temp->title);
		struct MP3 *t = temp;
		temp = temp->next;
		free(t);}

    return 0;
}
