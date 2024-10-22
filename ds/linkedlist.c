#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node *next;
};

void traverse(struct node *ptr)
{
   while (ptr->next!=NULL){
    printf("The value of nodes is %d\n",ptr->data); 
    ptr=ptr->next;
   }
}
// inserting at ending of the list 
struct node *insert_end(struct node *head,int data){
   struct node *new=(struct node *)malloc(sizeof(struct node));
   new->data=data;
   struct node *ptr=head;
   while (ptr->next!=NULL){
      ptr=ptr->next;
   }
   ptr->next=new;
   new->next=NULL;
   return head;

}
// inseting in the beginnig of the list 
struct node *insert_begi(struct node *head,int data){
   struct node *new=(struct node *)malloc(sizeof(struct node));
   new->data=data;
   struct node *ptr=head;
   new->next=ptr;
   return new;
}

// inserting through index value
 struct node *insert_index(struct node *head,int index,int val)
{
   struct node *ptr =head;
   struct node *ptr1 =head->next;
   struct node *new;
   new=(struct node *)malloc(sizeof(struct node));
   new->data=val;
   for(int i=0;i<index-1;i++){
      ptr=ptr->next;
      ptr1=ptr1->next;
   }
   ptr->next=new;
   new->next=ptr1;
   return head;
}
// inserting after a given node
struct node *insert_node(struct node *head,int data,struct node *address)
{
   struct node *new=(struct node *)malloc(sizeof(struct node));
   new->data=data;
   new->next=address->next;
   address->next=new;
   return head;
}
// delete from index of the  node 
struct node *delete(struct node *head,int ind)
{
   struct node *ptr =head;
   struct node *ptr1 =head->next;
   for(int i=0;i<ind-1;i++){
      ptr=ptr->next;
      ptr1=ptr1->next;
   }
   ptr->next=ptr1->next;
   free(ptr1);
   return head;
}
// delete from after a node.
struct node *deleteaft(struct node *head,int num)
{
   struct node *ptr =head;
   struct node *ptr1 =head->next;
   while(ptr->data!=num || ptr->next!=NULL){
     ptr=ptr->next;
     ptr1=ptr1->next;
   }
   if(ptr==NULL){
      printf("element not exists\n");
   }
   ptr=ptr1->next;
   free(ptr1);
   return head;
}
// delete from the last of the node 
struct node *dellast(struct node *head){
   struct node *p=head;
   struct node *q=head->next;
   while(q->next!=NULL){
      p=p->next;
      q=q->next;
   }
   p->next=NULL;
   free(q);
   return head;
}
// delete from the begining of the node
struct node *delfirst(struct node *head){
   struct node *p=head;
   struct node *q=head->next;
   // q->next=p->next;
   free(p);
   return q;
}
int main (){
   struct node *head;
   struct node *second;
   struct node *third;
   int n;
//node creation 
   head= (struct node *)malloc(sizeof(struct node ));
   second= (struct node *)malloc(sizeof(struct node ));
   third= (struct node *)malloc(sizeof(struct node ));
   
   //value inserting in the nodes 

   head->data=34;
   head->next=second;

   second->data=23;
   second->next=third;

   third->data=68;
   third->next=NULL;
   // printf("1.for insert in the begin\n");
   // printf("2. for insert in the end\n");
   // printf("3. for insert at index \n");
   // printf("4.for insert at node\n");
   // printf("5.for delete at first\n");
   // printf("6.for delete at last\n");
   // printf("7.for delete at node\n");
   // printf("8.for exit\n");
   // printf("enter the operation:");
   // scanf("%d",n);
   // head=insert_end(head,56);
   // head=insert_begi(head,12);
   // head=insert_index(head,2,11);
   // head=insert_node(head,90,head); //adding after a particular address


   // head=delete(head,1);
   // head=dellast(head);
   // head=delfirst(head);
   //  head=deleteaft(head,23);

   // display the linked list
   traverse(head);
   return 0;
}