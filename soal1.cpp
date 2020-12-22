#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    Node *next;
};

void pushHead(struct Node** set, int number) { 
    Node* new_node = (Node*) malloc(sizeof(Node)); 
    new_node->value  = number; 
    new_node->next = (*set); 
    (*set) = new_node; 
} 

Node* Merge(Node* a, Node* b){ 
    Node *temp = NULL; 
    if (a == NULL)  
        return(b); 
    else if (b==NULL)  
        return(a); 
    if (a->value < b->value){ 
        temp = a; 
        temp->next = Merge(a->next, b); 
    } 
    else { 
        temp = b; 
        temp->next = Merge(a, b->next); 
    } 
    return(temp); 
}

void printLinkedList (Node *node){
    while (node != NULL){
        printf ("%d ",node ->value);
        node = node -> next;
    }
}

int main(){
    Node *a = NULL;
    Node *b = NULL;
    Node *ans = NULL;
    pushHead (&a, 25);
    pushHead (&a, 18);
    pushHead (&a, 6);
    pushHead (&b, 30);
    pushHead (&b, 12);
    pushHead (&b, 4);
    ans = Merge(a, b);
    printf ("Sort Linked list:\n");
    printLinkedList(ans);
}