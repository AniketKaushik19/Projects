#include<stdio.h>
#include<stdlib.h>

struct node {
    int coef;
    int expo;
    struct node *next;
};

struct node *create(struct node *l1,int coef,int expo){
    struct node *ptr=(struct node *)malloc(sizeof(struct node)),*temp=l1;

    ptr->coef=coef;
    ptr->expo=expo;
    ptr->next=NULL;
    if(l1==NULL){
        l1=ptr;
        return l1;
    }
    while(l1->next!=NULL){
        l1=l1->next;
    }
    l1->next=ptr;
    return temp;
}
void display(struct node *l1){
    while(l1!=NULL){
        if (l1->coef<0)
        {
            printf("%dx^%d",l1->coef,l1->expo);
        }
        else{
            printf("+%dx^%d",l1->coef,l1->expo);
        }     
        l1=l1->next;
    }
}

struct node *add(struct node *l1,struct node *l2){
    struct node *l3=NULL,*ptr,*trail=NULL;
    while (l1!=NULL && l2!=NULL)
    { 
        ptr=(struct node *)malloc(sizeof(struct node));
        ptr->next=NULL;
        if(l1->expo==l2->expo){
            ptr->coef=l1->coef+l2->coef;
            ptr->expo=l1->expo;
            l1=l1->next;
            l2=l2->next;
        }
        else if(l1->expo>l2->expo){
            ptr->coef=l1->coef;
            ptr->expo=l1->expo;
            l1=l1->next;
        }
        else{
            ptr->coef=l2->coef;
            ptr->expo=l2->expo;
            l2=l2->next;
        }  
        if(l3==NULL){
            l3=ptr;
            trail=ptr;
        
        }
        else{
            trail->next=ptr;
            trail=ptr;
          
        }
    }
    return l3;
}
void main(){
     struct node *l1=NULL,*l2=NULL,*l3=NULL;
     int coef, expo,tn,i;
     printf("enter the number of term of l1:");
     scanf("%d",&tn);
     for(i=0;i<tn;i++){
        printf("enter the coef %d:",i+1);
        scanf("%d",&coef);
        printf("enter the expo %d:",i+1);
        scanf("%d",&expo);
        l1=create(l1,coef,expo);
    }
    printf("enter the number of term of l2:");
    scanf("%d",&tn);
    for(i=0;i<tn;i++){
        printf("enter the coef %d:",i+1);
        scanf("%d",&coef);
        printf("enter the expo %d:",i+1);
        scanf("%d",&expo);
        l2=create(l2,coef,expo);
    }
    l3=add(l1,l2);
    printf("\nfirst polnomial\n");
    display(l1);
    printf("\nsecond polnomial\n");
    display(l2);
    printf("\naddition of  polnomial\n");
    display(l3);
}