#include<stdio.h>
#include<stdlib.h>
struct node {
int coef;
int exp;
struct node *next;
};
struct node *create(struct node *list, int coef, int exp)
{
struct node *ptr,*l;
l=list;
ptr =(struct node *)malloc(sizeof(struct node));
ptr->coef=coef;
ptr->exp=exp;
ptr->next=NULL;
if (list==NULL){
list=ptr;
return list;
}
while(list->next!=NULL)
list=list->next;
list->next=ptr;
return l;
}
void display(struct node *list)
{
while(list!=NULL)
{
if(list->coef<0)
printf("%dx^%d",list->coef,list->exp);
else
printf("+%dx^%d",list->coef,list->exp);
list=list->next;
}
}
struct node *addition(struct node *l1,struct node *l2)
{
struct node *l3=NULL,*ptr,*trail=NULL;
while(l1!=NULL && l2!=NULL)
{
ptr=(struct node *)malloc(sizeof(struct node));
ptr->next=NULL;
if(l1->exp==l2->exp)
{
ptr->coef=l1->coef+l2->coef;
ptr->exp=l1->exp;
l1=l1->next;
l2=l2->next;
}
else if(l1->exp>l2->exp){
ptr->coef=l1->coef;
ptr->exp=l1->exp;
l1=l1->next;
}
else
{
ptr->coef=l2->coef;
ptr->exp=l2->exp;
l2=l2->next;
}
if(l3==NULL)
{
l3=ptr;
trail=ptr;
}
else
{
trail->next=ptr;
trail=ptr;
}
}
return l3;
}
void main(){
struct node *list1=NULL, *list2=NULL, *list3=NULL;
int c,e,tn,i;
printf("\nEnter first polynomial expression");
printf("\nEnter number of term");
scanf("%d",&tn);
for(i=1;i<=tn;i++)
{
printf("\nEnter coefficient:");
scanf("%d",&c);
printf("\nEnter exponent;");
scanf("%d",&e);
list1=create(list1,c,e);
}
printf("\nEnter second polynomial expression;");
printf("\nEnter Number of expression:");
scanf("%d",&tn);
for(i=1;i<=tn;i++)
{
printf("\nEnter coefficient:");
scanf("%d",&c);
printf("\nEnter Exponent");
scanf("%d",&e);
list2=create(list2,c,e);
}
list3=addition(list1,list2);
printf("\nFirst polynpmial \n");
display(list1);
printf("\nSecond Plynomial\n");
display(list2);
printf("\nAddition of two polynomials\n");
display(list3);

}