#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
struct stack{
    int size;
    int top;
    char *sp;
};

int isempty(struct stack *s){ 
   if(s->top==-1){
      return 1;
   }
   else{
    return 0;
   }
} 

int isfull(struct stack *s){ 
   if(s->top==s->size-1){
      return 1;
   }
   else{
    return 0;
   }
} 

void  push(struct stack *s,char val){
    if(isfull(s)){
       printf("your stack is full for entering the value\n");
    }
    else{
        s->sp[s->top]=val;
        s->top++;
        printf("your value is entered... %c\n",val);
    }
}

int pop(struct stack *s){
    if(isempty(s)){
      printf("your stack is empty for pop the value\n");
    }
    else{
    char value=s->sp[s->top-1];
    s->top--;
    printf("your stack is pop the value...%c\n",value);
    }
    return 0;
}

int parentisis(char *exp){
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->size=14;
    s->top=-1;
    s->sp=(char *)malloc(s->size*sizeof(char));
    for(int i=0;i<12;i++){
      if(exp[i]=='('){
        push(s,'(');
     }
     if(exp[i]==')'){
        if(isempty(s)){
        return 0;
    }
        pop(s);
     }
    }
    if(isempty(s)){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    char exp[]="(a*b+(c)-d";
    if(parentisis(exp)){
        printf("parentisis matched");
    }
    else{
     printf("not matched paranthisis");
    }
    return 0;
}