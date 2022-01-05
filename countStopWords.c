#include "headerA3.h"
#include "helper.h"

void countStopWords(tweet * tweetList){
  int stopCount;
  int tweetCount = 0;
  char delimiter[100];
  char stopWords[25][5] = {"a","an","and","are","as","at","be","by","for","from","has","he","in","is","it","its","of","on","that","the","to","was","were","will","with"}; //stores stop words in variable
  char * text = NULL;
  text = (char*) malloc(sizeof(tweet)); //allocates memory for text
  stopCount = 0;
  if(tweetList == NULL){
    printf("There are no tweets to count for stop words.\n");
    return;
  }
  while(tweetList != NULL){
    strcpy(text, tweetList->text);
    for(int i = 0; i < strlen(text); i++){ //loops through each letter of text
      text[i] = tolower(text[i]); //convert text to lower case
    }
    for(int i = 0; i < strlen(text); i++){
      if(isalpha(text[i]) == 0){ //checks for garbage data
        text[i] = ' '; //replaces anything not a letter with a space
      }
    }
    strcpy(delimiter, " ");
    char *ptr = strtok(text, delimiter);
    for(int i = 0; i < 25; i++){
      if(strcmp(ptr, stopWords[i]) == 0){ //checks if word is stopword
        stopCount++; //adds 1 to stopcount
      }
    }
    while(ptr != NULL){
      ptr = strtok(NULL, delimiter);
      if(ptr != NULL){
        for(int i = 0; i < 25; i++){
          if(strcmp(ptr, stopWords[i]) == 0){
            stopCount++;
          }
        }
      }
    }
    tweetList = tweetList->next; //points to next tweet memory address
    tweetCount++; //adds 1 to number of tweets
  }
  if(tweetCount == 1 && stopCount == 1){
    printf("Across %d tweet, %d stop word was found.\n", tweetCount, stopCount);
  }
  else if(tweetCount == 1 && stopCount > 1){
    printf("Across %d tweet, %d stop words were found.\n", tweetCount, stopCount);
  }
  else if(tweetCount > 1 && stopCount == 1){
    printf("Across %d tweets, %d stop word was found.\n", tweetCount, stopCount);
  }
  else{
    printf("Across %d tweets, %d stop words were found.\n", tweetCount, stopCount);
  }
  return;
}
