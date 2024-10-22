#include<stdio.h>
// wrong program
void heap(int a[],int n);
void print(int a[],int n);

void  print(int a[],int n){
    for(int i=0;i<n;i++){
       printf("%d\t",a[i]); 
    }
    printf("\n");
}
void  main(){
    int n,i;
    printf("enter the number of element");
    scanf("%d",&n);
    int a[n];
    printf("enter the element");
    for (i=0;i<n;i++){
    scanf("%d",&a[i]);
    }
    heap(a,n);
}
void heap(int a ,int n){

}