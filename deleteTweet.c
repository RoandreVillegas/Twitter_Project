#include "headerA3.h"
#include "helper.h"
void deleteTweet(tweet ** tweetList){
  int tweetCount = 0;
  int tweetChoice;
  char tweetConvert[4];
  tweet * previousTweet = NULL;
  tweet * head = *tweetList;

  if(*tweetList == NULL){ //checks if there are any tweets
    printf("There are no tweets to delete.\n");
    return;
  }
  while(*tweetList != NULL){
    *tweetList = (*tweetList)->next; //points to next tweet
    tweetCount++; //counts number of tweets
  }
  if(tweetCount == 1){ //checks if there is only 1 tweet
      printf("Currently there is %d tweet.\n", tweetCount);
  }
  else{
      printf("Currently there are %d tweets.\n", tweetCount);
  }
  tweetChoice = 0; //initialize tweetChoice
  while (tweetChoice < 1 || tweetChoice > tweetCount) {
    printf("Which tweet do you wish to delete - enter a value between 1 and %d: ", tweetCount);
    fflush(stdin);
    fgets(tweetConvert, sizeof(tweetConvert), stdin);
    fflush(stdin);
    tweetChoice = atoi(tweetConvert);
  }
  *tweetList = head; //save head node
  if(tweetChoice == 1){
    head = (*tweetList)->next;
  }
  else{
    for(int i = 0; i < tweetChoice - 1; i++){
      previousTweet = *tweetList; //save memory address into previousTweet
      *tweetList = (*tweetList)->next; //points to next tweet
    }
    previousTweet->next = (*tweetList)->next; //update new tweet's previous tweet's next
  }
  tweetCount--; //removes 1 from tweetCount
  if(tweetCount == 1){
    printf("Tweet %d deleted. There is now %d tweet left.\n", (*tweetList)->id, tweetCount);
  }
  else{
    printf("Tweet %d deleted. There are now %d tweets left.\n", (*tweetList)->id, tweetCount);
  }
  free(*tweetList); //frees unused memory
  *tweetList = head; //restores head node
  return;
}
