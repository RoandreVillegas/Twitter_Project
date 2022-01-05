#include "headerA3.h"
#include "helper.h"
int main(){
  int menuNum;
  char menuChar[4];
  tweet *head = NULL;
  tweet *newTweet = NULL;
  tweet *tweetList = NULL;
  do{
    printf("********************Gryphon Twitter********************\n");
    printf("Different tasks to choose from: ");
    printf("\n");
    printf("1. Create a new tweet\n");
    printf("2. Display tweets\n");
    printf("3. Search a tweet (by keyword)\n");
    printf("4. Find how many words are stop words\n");
    printf("5. Delete the nth tweet\n");
    printf("6. Save tweets to a file\n");
    printf("7. Load tweets from a file\n");
    printf("8. Exit\n");
    printf("*******************************************************\n");
    printf("Choose a menu option: ");
    fflush(stdin);
    fgets(menuChar, sizeof(menuChar), stdin);
    fflush(stdin);
    menuNum = atoi(menuChar);
    switch(menuNum){
      case 1:
        newTweet = createTweet(head);
        if(newTweet != NULL){
          addNodeToList(&head, newTweet);
        }
        break;
      case 2:
        displayTweets(head);
        break;
      case 3:
        searchTweetsByKeyword(head);
        break;
      case 4:
        countStopWords(head);
        break;
      case 5:
        deleteTweet(&head);
        break;
      case 6:
        saveTweetsToFile(head);
        break;
      case 7:
        loadTweetsFromFile(&head);
        break;
      case 8:
        break;
      default:
        printf("Not a valid input...\n");
    }
  } while(menuNum != 8);
  if(head != NULL){
    tweetList = head;
    while(tweetList != NULL){
      free(tweetList); //frees tweet memory
      tweetList = tweetList->next;
    }
  }
  printf("Thank you for using our nice system!\n");
}
