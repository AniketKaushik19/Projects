#include<stdio.h>
void selection(int a[],int n);
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
    selection(a,n);
}
void selection(int a[],int n){
    int i,j,min;
    for(i=0;i<n-1;i++){
        min=i;
        for (j=i+1;j<=n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        if(i!=min){    
            a[i]=a[i]+a[min];
            a[min]=a[i]-a[min];
            a[i]=a[i]-a[min];
        }
        print(a,n);
    }
}
