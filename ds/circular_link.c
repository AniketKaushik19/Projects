#include<stdio.h>
#include<stdlib.h>

struct node {
    int data ; 
    struct node *next;
};

void traverse(struct node *first)
{
   struct node *ptr=first;
   do{
    printf("The value of nodes is %d\n",ptr->data); 
    ptr=ptr->next;
   }while (ptr!=first);
}

int main(){
    struct node *first=(struct node * )malloc(sizeof(struct node ));
    struct node *second=(struct node * )malloc(sizeof(struct node ));
    struct node *third=(struct node * )malloc(sizeof(struct node ));

    first->data=44;
    first->next=second;

    second->data=12;
    second->next=third;

    third->data=44;
    third->next=first;

    traverse(first);
    return 0;
}