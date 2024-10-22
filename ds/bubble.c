#include<stdio.h>
void bubble(int arr[],int n);
void print(int arr[],int n);

void  print(int arr[],int n){
    for(int i=0;i<n;i++){
       printf("%d\t",arr[i]); 
    }
    printf("\n");
}
void  main(){
    int n,i;
    printf("enter the number of element");
    scanf("%d",&n);
    int arr[n];
    printf("enter the element");
    for (i=0;i<n;i++){
    scanf("%d",&arr[i]);
    }
    bubble(arr,n);
}
void  bubble(int arr[],int n){
    int i,j;
    for ( i= 0; i<n; i++)
    {
     for( j=0;j<=n-i-1;j++){

       if(arr[j]>arr[j+1]){
        arr[j]=arr[j]+arr[j+1];
        arr[j+1]=arr[j]-arr[j+1];
        arr[j]=arr[j]-arr[j+1];
       }
     }
    }
    printf("sorted array is :\n");
    print(arr,n);    
    
}
