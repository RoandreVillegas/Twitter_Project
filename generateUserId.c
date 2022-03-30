#include "headerA3.h"
int checkDuplicateUserID(tweet * tweetList, int userId){
  while(tweetList != NULL){
    if(tweetList->id == userId){
      return 1; //duplicate ID is found
    }
    tweetList = tweetList->next;
  }
  return 0; //unique ID
}

int generateUserID(tweet * tweetList, char * userName, char * tweet) {
  int userId = 0;

  for (int i=0; i<=strlen(userName); i++) { //loops through each letter of userName
    userId = userId + userName[i]; //add ASCII values of userName letters
  }
  userId = userId + strlen(tweet); //adds the length of userName to userId

  while(checkDuplicateUserID (tweetList, userId) == 1) { //checks if ID exists
    userId = userId + rand() % 1000; //generates random number between 1 and 999
  }
  return userId; //returns ID to createTweet function
}
