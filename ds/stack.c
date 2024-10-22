#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *sp;
};

int isempty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isfull(struct stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *s, int val)
{
    if (isfull(s))
    {
        printf("your stack is full for entering the value\n");
    }
    else
    {
        s->sp[s->top] = val;
        s->top++;
        // printf("your value is entered... %d\n", val);
    }
    return;
}

 int display(struct stack *s){
    if(isempty(s)){
        printf("unable to display");
    }
    else{
        while (s->top!=-s->size)
        {
            printf("value is %d\n",s->sp[s->top]);
            s->top++;
        }   
    }
    return; 
}
void peek(struct stack *s, int pos)
{
    int index = s->top-pos;
    if (index == -1)
    {
        printf("not valild ...");
        return;
    }
    else
    {
        printf("value at %d postition is %d", pos, s->sp[index]);
        return;
    }
}
int pop(struct stack *s)
{
    if (isempty(s))
    {
        printf("your stack is empty for pop the value\n");
    }
    else
    {
        int value = s->sp[s->top];
        s->top--;
        printf("your stack is poped the value...%d\n", value);
    }
    return ;
}
int main()
{
    int num, choice;
    struct stack *s;
    s->size = 4;
    s->top = -1;
    s->sp = (int *)malloc(s->size * sizeof(int *));
    do
    {
        printf("the operations are:\n");
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.DISPLAY\n");
        printf("4.PEEK\n");
        printf("5.EXITING\n");
        printf("enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter the value for push:");
            scanf("%d",&num);
            push(s, num);
            break;
        case 2:
            pop(s);
            break;
        case 3:
            printf("entered values are:\n");
            display(s);
            break;
        case 4:
            printf("enter the position:");
            scanf("%d", &num);
            peek(s,num);
            break;
        case 5:
            printf("exiting...");
            break;
        default:
            printf("invalid operation\n");
            break;
        }
    }while(choice!=5);
    return 0;
}