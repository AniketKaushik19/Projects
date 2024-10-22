#include<stdio.h>
void merge(int a[],int mid ,int lo,int hi);
void ms(int a[],int lo,int hi);
void print(int a[],int n);

void  print(int a[],int n){
    for(int i=0;i<n;i++){
       printf("%d\t",a[i]); 
    }
    printf("\n");
}

int main(){
    int n,i;
    printf("enter the number of element");
    scanf("%d",&n);
    int a[n];
    printf("enter the element");
    for (i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    ms(a,0,n-1);
    print(a,n);
    return 0;
}
void merge(int a[], int mid ,int lo , int hi ){
   int i,j,k;
   int b[hi+1] ;
   i=lo,j=mid+1,k=lo;
   while(i<=mid && j<=hi){
        if(a[i]<a[j]){
            b[k]=a[i];
            i++;k++;
        }
        else{
            b[k]=a[j];
            j++;k++;
        } 
   }  
   while(i<=mid){
        b[k]=a[i];
        k++;i++;
   }
   while(j<=hi){
        b[k]=a[j];
        k++;j++;
   }
   for (int i=lo; i<=hi; i++)
   {
    a[i]=b[i];
   }
}
void ms(int a[],int low,int hi){
    int mid;
    if(low<hi){
        mid=(low+hi)/2;
        ms(a,low,mid);
        ms(a,mid+1,hi);
        merge(a,mid,low,hi);
        print(a,hi);
    }
}