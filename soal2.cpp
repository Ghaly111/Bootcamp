#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    Node *next; 
} *head, *tail, *list;

Node *createNode(int num) {
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

void pushTail(int num) {
    Node *temp = createNode(num);
    if (!head) {
        head = tail = temp;
    }else {
        tail->next = temp;
        tail = temp;
    } 
}
 
int detectLoop(Node *list) {
    struct Node *slow;
    struct Node *fast;
    slow = list; 
    fast = list;
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return 1;
        }
    }
    return 0;
}

void printLinkedList() {
    struct Node *curr = head;
    while (curr) {
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    pushHead(35);
    pushHead(27);
    pushTail(46);
    pushTail(38);
    printLinkedList();
    head->next->next->next->next = head;
    if (detectLoop(head)) {
        printf("Has a cycle\n");
    }else {
        printf("Hasn't a cycle\n");
    }
    return 0;
}