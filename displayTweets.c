#include "headerA3.h"
#include "helper.h"

void displayTweets(tweet * tweetList){
  if(tweetList == NULL){ //checks if there are any tweets
    printf("There are no tweets to display.\n");
    return;
  }
  while(tweetList != NULL){
    printf("%d: Created by %s: %s\n", tweetList->id, tweetList->user, tweetList->text); //displays id, user and tweet
    tweetList = tweetList->next; //points to next tweet
  }
  return;
}
