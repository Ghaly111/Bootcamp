#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node { 
    int value; 
    Node *next; 
}*head, *tail, *curr; 

Node *createNode(int num){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = num;
    newNode->next = NULL;
    return newNode;
}

void pushHead(int num) { 
    Node *temp = createNode(num);
    if (!head) {
        head = tail = temp;
    }else {
        temp->next = head;
        head = temp;
    } 
}
 
void removeDuplicates(Node *head) { 
    Node *current = head; 
    Node* next_next; 
    if (current == NULL)  
       return;  
  
    while (current->next != NULL) {
       if (current->value == current->next->value) {               
           next_next = current->next->next; 
           free(current->next); 
           current->next = next_next;   
       } 
       else 
       { 
          current = current->next;  
       } 
    } 
}  

void printLinkedList(Node *node) 
{ 
    while (node!=NULL) 
    { 
       printf("%d ", node->value); 
       node = node->next; 
    } 
}  

int main() {  
    pushHead(36); 
    pushHead(19); 
    pushHead(19);   
    pushHead(15); 
    pushHead(15); 
    pushHead(15);                                     
  
    printf("\n Linked list have duplicate : "); 
    printLinkedList(head);  
 
    removeDuplicates(head);  
  
    printf("\n Linked list after duplicate remove : ");          
    printLinkedList(head);             
    
    return 0; 
}