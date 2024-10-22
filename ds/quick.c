#include<stdio.h>
void quick(int a[],int low,int hi);
void  print(int a[],int n);
int partition(int a[] ,int low,int hi);

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
    quick(a,0,n-1);
    print(a,n);
}
void quick(int a[],int low,int hi){
    // int parti;
    if(low<hi){
       int parti=partition(a,low,hi);
        quick(a,low,parti-1);
        quick(a,parti+1,hi);
    }
}
int partition(int a[] ,int low,int hi){
    int i=low+1;
    int j=hi,temp;
    int piv=a[low];
    do{
        while(a[i]<=piv){
            i++;
        }
        while(a[j]>piv){
            j--;
        }
        if (i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);
    temp=a[low];
    a[low]=a[j];
    a[j]=temp;
    return j;
}
