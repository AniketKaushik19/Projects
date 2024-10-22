#include<stdio.h>
#include<stdlib.h>

struct node
{
   struct node *pre;
   int data;
   struct node *next;      
};

 int isfull(struct node *ptr){
   while(ptr!=NULL){
      ptr=ptr->next;
   }
   printf("linked list overflow\n");
   return 0;
}

int isempty(struct node *ptr){
   while(ptr!=NULL){
      ptr=ptr->next;
}
      printf("linked list underflow\n");
      return 0;
}

struct node *display(struct node *ptr){
   while(ptr!=NULL){
      printf("node is %d\n",ptr->data);
      ptr=ptr->next;
   }
}
struct node *displayrev(struct node *tail){
   while(tail!=NULL){
      printf("node is %d\n",tail->data);
      tail=tail->pre;
   }
}

struct node *insertbg(struct node *ptr,int data){
   struct node *new=(struct node *)malloc(sizeof(struct node));
   new->pre=NULL;
   new->data=data;
   new->next=ptr;
   ptr->pre=new;
   return new;
}

struct node *insertlast(struct node *ptr,int data){
   struct node *temp=ptr;
   while(temp->next!=NULL){
      temp=temp->next;
   }
   struct node *new=(struct node *)malloc(sizeof(struct node));
   new->pre=temp;
   new->data=data;
   new->next=NULL;
   temp->next=new;
   return ptr;
}
 
struct node *insertpos(struct node *ptr,int pos,int data){
   struct node *temp=ptr;
   int co=1;
   while(co==pos){
      temp=temp->next;
      co++;
   }
   struct node *new=(struct node *)malloc(sizeof(struct node));
   new->pre=temp;
   new->data=data;
   new->next=temp->next;
   temp->next=new;
   return ptr;
}

struct node *deletebg(struct node *ptr){
   struct node *temp=ptr;
   struct node *temp1=ptr->next;
   free(temp);
   return temp1;   
}

struct node *deletelast(struct node *ptr){
   struct node *temp=ptr;
   struct node *temp1=ptr->next;
   while(temp1->next!=NULL){
      temp1=temp1->next;
      temp=temp->next;
   }
   temp->next=NULL;
   free(temp1);
   return ptr;
}

struct node *deletepos(struct node *ptr,int pos){
   struct node *temp=ptr;
   struct node *temp1=ptr->next;
   int co=1;
   if(pos==1){
     ptr=deletebg(ptr);
     return ptr;
   }
   while(co!=pos-1){
      temp=temp->next;
      temp1=temp1->next;
      co++;
   }
   temp->next=temp1->next;
   free(temp1);
   return ptr;
}
int main(){
   struct node *ptr=(struct node *)malloc(sizeof(struct node));
   struct node *ptr1=(struct node *)malloc(sizeof(struct node));
   struct node *ptr2=(struct node *)malloc(sizeof(struct node));

   ptr->pre=NULL;
   ptr->data=34;
   ptr->next=ptr1;
   
   ptr1->pre=ptr;
   ptr1->data=75;
   ptr1->next=ptr2;

   ptr2->pre=ptr1;
   ptr2->data=42;
   ptr2->next=NULL;

   displayrev(ptr2);
   // ptr=insertbg(ptr,789);
   // ptr=insertlast(ptr,56);
   // ptr=insertpos(ptr,1,156);
   // ptr=deletebg(ptr);
   // ptr=deletelast(ptr);   
   // ptr=deletepos(ptr,2);   
   // display(ptr);
   return 0;
}