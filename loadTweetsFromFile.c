#include "headerA3.h"
#include "helper.h"
void loadTweetsFromFile(tweet ** tweetList){
  int count;
  char fileName[51];
  char str[141];
  FILE * fileNamePtr;
  tweet * newTweet;
  tweet *head = *tweetList; //save head node

  strcpy(fileName,"\0"); // initialize file name variable
  while (strcmp(fileName, "\0") == 0 || strcmp(fileName, "\n") == 0) {
    printf("Enter a filename to load from: "); //prompts user for file name
    fflush(stdin);
    fgets(fileName, sizeof(fileName), stdin); //stores user input into fileName variable
    fflush(stdin);
  }
  if(fileName[strlen(fileName)-1] == '\n'){
    fileName[strlen(fileName)-1] = '\0'; //replaces newline with null character
  }
  fileNamePtr = fopen(fileName, "r"); //opens filename and stores into fileNamePtr
  if(fileNamePtr == NULL){ //checks if file opened successfully
    printf("File cannot open\n");
  }
  else{
    while(fgets(str, 141, fileNamePtr) != NULL){
      newTweet = (tweet*) malloc(sizeof(tweet)); //allocates memory for newTweet
      char *ptr = strtok(str, ",\r\n"); //extracts first word of the string
      newTweet->id = atoi(ptr); //converts ptr into integer
      count = 1;
      while(ptr != NULL){ //extracts succeeding words
        ptr = strtok(NULL, ",\r\n");
        count++;
        if(count == 2){
          strcpy(newTweet->user, ptr); //copies second data into user struct element
        }
        if(count == 3){
          strcpy(newTweet->text, ptr); //copies third data into text struct element
        }
        if(count > 3){    //in case tweet has imbedded comma
          if (ptr != NULL) {
            strcat(newTweet->text, ",");
            strcat(newTweet->text, ptr);
          }
        }
      }
      newTweet->next = NULL;
      if(head == NULL){ // check if tweetlist is empty (meaning, if loaded record is the first node)
        head = newTweet; // assign new node as head node
      }
      else{
        addNodeToList(&head, newTweet); //calls on addNodeToList function
      }
    }
    printf("Tweets Imported!\n");
  }
  *tweetList = head; //restores head node
  return;
}
