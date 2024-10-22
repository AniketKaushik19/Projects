#include<stdio.h>
void insertion(int a[],int n);
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
    insertion(a,n);
}
void  insertion(int a[],int n){
    int i,j,key;
    for ( i= 0; i<n; i++)
    {
      key=a[i];
      j=i-1;
      while(j>=0 && a[j]>key){
        a[j+1]=a[j];
        j--;
      }
      a[j+1]=key;
    }
    printf("sorted array is :\n");
    print(a,n);    
    
}
