#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int f; 
    int r;
    int *arr;
};

int isempty(struct queue *q ){
    if(q->f==q->r){
        return 1;
    }
    return 0;
}
int isfull(struct queue *q ){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
int enqueue(struct queue *q,int val){
    if(isfull(q)){
      printf("queue is overflow\n");
    }
    else{
     q->r++;
     q->arr[q->r]=val;
     printf("the value entered %d\n",val);
    }
}

int dequeue(struct queue *q ){
    if(isempty(q)){
      printf("queue is empty");
    }
    else{
     q->f++;
     int val=q->arr[q->f];
     printf("the value deleted %d\n",val);
    }
}

void main(){
 struct queue *q;
 q->size=4;
 q->arr=(int *)malloc(q->size*sizeof(int));
 q->f=-1;
 q->r=-1;
 enqueue(q,23);
 enqueue(q,234);
 enqueue(q,12);
 enqueue(q,2);
 dequeue(q);
 dequeue(q);
}