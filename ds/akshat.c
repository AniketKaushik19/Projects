#include <stdio.h>
#include<stdlib.h>
struct node{
struct node*prev;
int data;
struct node*next;
}*head,*tail;
void insrtbg(int);
void insrtlast(int);
void insrtatpos(int,int);
void delfirst(int);
void dellast(int);
void delpos(int,int);
void display();
void main()
{
 int num,pos,ch;
 do{
     printf("select any choice");
     printf("\n 1.insert at begining\n");
     printf("\n 2.insert at last\n");
     printf("\n 3.insert at specific position");
     printf("\n 4.delete at first");
     printf("\n 5.delete at last");
     printf("\n 6.delete at specific positon");
     printf("\n 7.display\n");
     printf("\n 8.exit\n");
     printf("\n enter your choice\n");
     scanf("%d",&ch);
     switch(ch)
     {
         case 1:printf("enter data");
         scanf("%d",&num);
         insrtbg(num);
         break;

         case 2: printf("enter data");
         scanf("%d",&num);
         insrtlast(num);
         break;
         case 3:printf("enter data");
         scanf("%d",&num);
           printf("enter position");
           scanf("%d",&pos);
         insrtatpos(num,pos);
         break;
       case 4:printf("enter data");
       scanf("%d",&num);
       delfirst(num);
       break;
       case 5: printf("enter data");
       scanf("%d",&num);
       dellast(num);
       break;
       case 6:printf("enter data");
       scanf("%d",&num);
       printf("enter position");
       scanf("%d",&pos);
       delpos(num,pos);
         case 7: display();
         break;
         case 8: printf("exiting");
         break;
         default: printf("invalid choice");
     }}
         while(ch!=8);
     }
     //functon insert at begining
void insrtbg(int num)
    {
        struct node*ptr;
        ptr=(struct node*)malloc(sizeof(struct node));
        if(ptr==NULL)
    {
        printf("memory overflow");
    return;
    }
  else
  {
      ptr->data=num;
      ptr->prev=NULL;
      if(head==NULL)
      {
      ptr->next=NULL;
      }
      else
      {
      ptr->next=head;
      head->prev=ptr;
      }
      head=ptr;
}}
//function insert at last
void insrtlast(int num)
{
    struct node*ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("memory overflow");
        return;
    }
    else
    {
        ptr->data=num;
        ptr->next=NULL;
        if(head==NULL)
        {
            ptr->prev=NULL;
        }
        else
        {
            tail->next=ptr;
            ptr->prev=tail;
        }
            tail=ptr;
        }
        printf("%d at successfully inserted at last",num);
}
// function at  specific position
void insrtatpos(int pos,int num)
{
    int count=0;
    struct node*ptr,*temp;
    temp=head;
    while(temp->next!=NULL && count!=pos)
        temp=temp->next;
        count++;
    if(count==0)
    {
        printf("given no.does not exist");
        return;
    }
    else{
        ptr=(struct node*)malloc(sizeof(struct node));
        if(ptr==NULL){
            printf("memory overflow");
            return;
        }
        else
        {
    ptr->next=temp;
    ptr->prev=temp->prev;
    temp->prev->next=ptr;
    temp->prev=ptr;
    }
}
}
// delete at first
void delfirst(int num){
struct node *temp;
if(head==NULL)
{
  printf("\n list does not exist");
  return;
}
  else{
  temp=head;
  head=head->next;
  head->prev=NULL;
  free(temp);
}}
// delete at last
void dellast(int num)
{
struct node *temp;
  if(tail==NULL)
  {
    printf("list does not exist");
    return;
  }
  else{
    temp=tail;
  tail=tail->prev;
    tail->prev->next=NULL;
    free(temp);
  }}
//delete at specific position
void delpos(int pos,int num){
  int i=1;
struct node *temp;
temp=head;
  while(i<pos)
    {
      temp=head;
      temp=temp->next;
      i++;
    }
  temp->prev->next=temp->next;
  temp->next->prev=temp->prev;
  free(temp);
}
//display
void display(){
    struct node *ptr=head;
    if(head==NULL){
        printf("list is empty");
        return;
    }
    printf("nodes of doubly linked list");
    while(ptr!=NULL)
    {
        printf("%d",ptr->data);
        ptr=ptr->next;
    }}