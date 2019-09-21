#include <stdio.h>
#include <stdlib.h>
#include "MP3.h"
#define BUFFER 20

int main(void) {
  struct MP3* head = NULL; 
  struct MP3* tail = NULL;
    char* artist1=(char*)malloc(sizeof(char));
    char* artist2=(char*)malloc(sizeof(char));
    char* title=(char*)malloc(sizeof(char));
    char yearMade[BUFFER];
    char runtime[BUFFER];
    int choice=1;
    int len;
    
    //struct MP3* node;
    node *mp3;

  
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

        scanf("%d", &choice);

        /*
         different menu options
         */
        switch(choice)
        {
            case 1:
            printf("\n");
                printf("Type in Artist Name: ");
                fgets(artist1, BUFFER, stdin);
                if (fgets(artist1, BUFFER, stdin) != NULL){
                  len = (int) strlen(artist1);
                  artist1[len - 1] = '\0';
                  mp3 = ( node *) malloc(sizeof(node));
                  mp3->artist_name = (char *) malloc(len);
                  strcpy(mp3->artist_name, artist1); 
                printf("\n");

                printf("Type in Title Name: ");
                 fgets(mp3->title, BUFFER, stdin);
                if (fgets(title, BUFFER, stdin) != NULL){
                  len = (int) strlen(title);
                  title[len - 1] = '\0';
                  mp3 = (node *) malloc(sizeof(node));
                  mp3->title = (char *) malloc(len);
                  strcpy(mp3->title, title);  

                printf("Type in Song's Year: ");
                fgets(yearMade, BUFFER, stdin);
                printf("Type in Runtime of Song: ");
                fgets(runtime, BUFFER, stdin);

                add_list(artist1,title, atoi(yearMade),atoi(runtime));
                  //free(artist1);   
                  //free(title); 
                break;
            case 2:
               printf("Type in Artist Name: ");
               fgets(artist2, BUFFER, stdin);
               deleteSong(artist2);

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

        printf("\n\n\n\n\n");
    }

    return 0;
}
    }
}




  

