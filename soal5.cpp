  
#include <assert.h> 
#include <stdio.h> 
#include <stdlib.h> 
  
struct Node{ 
  int value; 
  struct Node* next; 
}; 

void pushHead(struct Node** head, int temp){ 
  struct Node* newNode = (Node*)malloc(sizeof(Node*)); 
  newNode->value = temp; 
  newNode->next = (*head); 
  (*head) = newNode; 
} 

int GetNth(struct Node* head, int idx){ 
  struct Node* curr = head; 
  int ctr = 0; 
  while (curr != NULL) { 
    if (ctr == idx) {
        return (curr->value);
    } 
    ctr++; 
    curr = curr->next; 
  } 
  assert(0); 
} 
  
int main(){ 
  struct Node* head = NULL; 
  pushHead(&head, 40); 
  pushHead(&head, 35); 
  pushHead(&head, 30); 
  pushHead(&head, 23); 
  pushHead(&head, 18); 
  printf("Element at index 2 is %d", GetNth(head, 2)); 
  getchar(); 
}