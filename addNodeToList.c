#include "headerA3.h"
void addNodeToList(tweet**tweetList,tweet * node) {
  tweet *head = *tweetList; //stores head node into head variable
  if ((*tweetList) == NULL) {
    head = node; //assign new node as head node
  } else {
    while((*tweetList)->next != NULL) {
      *tweetList = (*tweetList)->next;
    }
    (*tweetList)->next = node; //store the new node's address to it's previous node's next pointer
  }
  *tweetList = head; //restores head node
  return;
}
