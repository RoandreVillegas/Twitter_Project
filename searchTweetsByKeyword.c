#include "headerA3.h"
#include "helper.h"

int searchTweetsByKeyword(tweet * tweetList){
  int match = 0;
  int tweetListMatch = 0;
  char * keyword = NULL;
  keyword = (char*) malloc(sizeof(char) * 141); //dynamically allocated memory for keyword
  char * keywordLower;
  keywordLower = (char*) malloc(sizeof(keyword));
  char * text = NULL;
  text = (char*) malloc(sizeof(tweet));

  if(tweetList == NULL){ //checks if tweetList has data
    printf("There are no tweets to search by keyword.\n");
    return 0;
  }
  strcpy(keyword,"\0"); //initialize file name variable
  while (strcmp(keyword, "\0") == 0 || strcmp(keyword, "\n") == 0) { //checks if any keyword was inputted
    printf("Enter a keyword to search: ");
    fflush(stdin);
    fgets(keyword, sizeof(keyword), stdin);
    fflush(stdin);
  }
  if(keyword[strlen(keyword)-1] == '\n'){
    keyword[strlen(keyword)-1] = '\0'; //replaces newline with null character
  }
  strcpy(keywordLower, keyword); //copies keyword into keywordLower
  for(int i = 0; i < strlen(keywordLower); i++){ //loops through each letter of keywordLower
    keywordLower[i] = tolower(keywordLower[i]); //converts letters to lowercase
  }
  while(tweetList != NULL){
    strcpy(text, tweetList->text); //copies tweet text into text variable
    for(int i = 0; i < strlen(text); i++){
      text[i] = tolower(text[i]);
    }
    match = 0; // initialize match indicator
    char *ptr = strstr(text, keywordLower);
    if(ptr != NULL){
      printf("Match found for '%s': %s wrote: %s\n", keyword, tweetList->user, tweetList->text);
      match = 1;
      tweetListMatch = 1;
    }
    tweetList = tweetList->next;
  }
  if(tweetListMatch == 0){
    printf("No match found for '%s'...\n", keyword);
  }
  return match;
}
