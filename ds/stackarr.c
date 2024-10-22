#include<stdio.h>
#include<stdlib.h>
# define size 5
int stk[size], top=-1;
int push(int num)
{
    if(top==size-1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stk[++top]=num;
}
int pop()
{
    if(top==-1)
    {
        printf("Stack empty\n");
        return;
    }
    printf("%d is poped from stack\n",stk[top]);
    top--;
}
int display()
{
    int i;
    for(i=top;i>=0;i--)
    printf("%d\n",stk[i]);
}
void main()
{
    int choice,num;
    do
    {
        printf("STACK OPERATION\n");
        printf("\n 1. push \n 2. pop \n 3. display\n 4. exit\n");
        printf("Enter your choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the element you want to insert");
            scanf("%d",&num);
            push(num);
            break;
            case 2: pop();
            break;
            case 3:
            printf("Following elements of stack are:\n");
            display();
            break;
            case 4: printf("EXITING");
            break;
            default: printf("invalid Choice");
        }
    }
    while(choice!=4);
}