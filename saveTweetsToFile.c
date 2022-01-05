#include "headerA3.h"
#include "helper.h"
void saveTweetsToFile(tweet * tweetList){
  int tweetCount = 0;
  FILE * fileNamePtr = NULL;
  char * fileName = NULL;
  fileName = (char*) malloc(sizeof(char)*51); //allocates memory for filename
  tweet * head = tweetList; //initializes tweetList with head node
  if(tweetList == NULL){
    printf("There are no tweets to save.\n");
    return;
  }
  while(tweetList != NULL){
    tweetList = tweetList->next;
    tweetCount++; //adds 1 to tweet count
  }
  if(tweetCount == 0){
    printf("There are no tweets to save.\n");
    return;
  }

  strcpy(fileName,"\0"); //initialize file name variable
  while (strcmp(fileName, "\0") == 0 || strcmp(fileName, "\n") == 0) {
    printf("Enter the filename where you would like to store your tweets: "); //prompts user for file name
    fflush(stdin);
    fgets(fileName, sizeof(fileName), stdin);
    fflush(stdin);
  }
  if(fileName[strlen(fileName)-1] == '\n'){
    fileName[strlen(fileName)-1] = '\0'; //replaces newline with null character
  }

  if ((fileNamePtr = fopen(fileName,"w")) == NULL) { //opens the file for writing
    printf("File cannot open"); //prints if file cannot open
    return;
  }
  tweetList = head; //restores head node into tweetList
  for(int i = 0; i < tweetCount; i++){
    fprintf(fileNamePtr, "%d,%s,%s\n", tweetList->id, tweetList->user, tweetList->text); //writes data into file
    tweetList = tweetList->next;
  }
  fclose(fileNamePtr); //closes file
  printf("Output successful!\n");
  return;
}
