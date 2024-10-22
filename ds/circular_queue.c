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
    if(q->f==q->r+1%(q->size)){
        return 1;
    }
    return 0;
}
void enqueue(struct queue *q,int val){
    if(isfull(q)){
      printf("queue is overflow\n");
    }
    else{
     q->r=q->r+1%(q->size);
     q->arr[q->r]=val;
     printf("the value entered %d\n",val);
    }
}

void dequeue(struct queue *q ){
    if(isempty(q)){
      printf("queue is empty");
    }
    else{
     q->f=q->f+1%(q->size);
     int val=q->arr[q->f];
     printf("the value deleted %d\n",val);
    }
}

void main(){
 struct queue *q;
 q->size=4;
 q->arr=(int *)malloc(q->size*sizeof(int));
 q->f=0;
 q->r=0;
 enqueue(q,23);
 enqueue(q,234);
 enqueue(q,12);
 enqueue(q,2);
 dequeue(q);
 dequeue(q);
 dequeue(q);
 dequeue(q);
 enqueue(q,82);
 enqueue(q,02);
 enqueue(q,52);
 enqueue(q,442);
}