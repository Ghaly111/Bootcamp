#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
  int value;
  Node *next;
}*head;

Node *createNode(int num){
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->value = num;
  newNode->next = NULL;
  return newNode;
}

void pushHead(int data){
  Node *temp = createNode(data);
  if(!head){
    head = temp;
  } else {
    temp->next = head;
    head = temp;
  }
}

void printLinkedList(){
  Node *curr = head;
  while(curr){
    printf("%d ",curr->value);
    curr = curr->next;
  }
  printf("\n");
}

int main() {
  pushHead(1);
  pushHead(2);
  pushHead(3);
  pushHead(4);
  pushHead(5);

  printLinkedList();

  return 0;
}