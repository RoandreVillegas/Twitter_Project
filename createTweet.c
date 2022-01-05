#include "headerA3.h"
#include "helper.h"

tweet * createTweet(tweet * tweetList){
  int userID = 0;
  char userName[1024];
  char userTweet[1024];
  tweet *head = tweetList;
  tweet *newTweet = NULL;
  newTweet = (tweet*) malloc(sizeof(tweet)); //allocate memory for tweet

  strcpy(userName,"\0"); //initializes userName
  while (strcmp(userName, "\0") == 0 || strcmp(userName, "\n") == 0) {
    printf("Enter a username: "); //prompts user for username
    fflush(stdin);
    fgets(userName, sizeof(userName), stdin);
    fflush(stdin);
  }
  if(strlen(userName) > 50){
    printf("Username is too long.\n");
    return NULL;
  }
  if(userName[strlen(userName)-1] == '\n'){
    userName[strlen(userName)-1] = '\0'; //replaces newline with null character
  }
  strcpy(newTweet->user, userName); //copies username into struct user

  strcpy(userTweet,"\0");
  while (strcmp(userTweet, "\0") == 0 || strcmp(userTweet, "\n") == 0) {
    printf("Enter the user's tweet: "); //prompts user for username
    fflush(stdin);
    fgets(userTweet, sizeof(userTweet), stdin);
    fflush(stdin);
  }
  if(strlen(userTweet) > 140){
    printf("Tweet is too long.\n");
    return NULL;
  }
  if(userTweet[strlen(userTweet)-1] == '\n'){
    userTweet[strlen(userTweet)-1] = '\0';
  }
  strcpy(newTweet->text, userTweet); //copies tweet into struct text
  newTweet->next = NULL;
  userID = generateUserID(head, userName, userTweet); //calls on helper function
  newTweet->id = userID;

  printf("Your computer-generated userid is %d.\n", newTweet->id);

  return newTweet;
}
