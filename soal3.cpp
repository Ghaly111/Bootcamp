#include <stdio.h>
#include <stdlib.h>
 
struct Node{
  int value;
  Node *next;
};
 
void middlenode(struct Node *head){
  struct Node *p, *q;
  int flag = 0;
 
  q = p = head;
  while (q->next != NULL){
    q = q->next;
    if (flag){
      p = p->next;
    }
    flag = !flag;
  }
  if (flag){
    printf("List contains even number of nodes\nThe middle two node's values are: %d  %d\n", p->next->value, p->value);
  } else{
    printf("The middle node of the list is: %d\n", p->value);
  }
}
 
void create(struct Node **head)
{
  int c, ch;
  struct Node *temp;
 
  do{
    printf("Enter number: ");
    scanf("%d", &c);
    temp = (Node*)malloc(sizeof(Node*));
    temp->value = c;
    temp->next = *head;
    *head = temp;
    printf("Add another number to your list? [0/1]: ");
    scanf("%d", &ch);
    } while (ch != 0);
    printf("\n");
}
 
void release(struct Node **head)
{
  struct Node *temp = *head;
  *head = (*head)->next;
  while ((*head) != NULL){
    free(temp);
    temp = *head;
    (*head) = (*head)->next;
  }
}
 
int main(){
  struct Node *p = NULL;
 
  printf("Enter data into the list\n");
  create(&p);
  middlenode(p);
  release (&p);
 
  return 0;
}