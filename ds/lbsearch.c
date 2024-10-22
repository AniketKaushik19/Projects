#include<stdio.h>

void linear(int *arr,int val,int n){
   int count=0;
   for(int i=0;i<n;i++){
    if(arr[i]==val){
        printf("founded at %d, value is %d",i,val);
        count++;
    }
   }
   if(count==0){
    printf("not found in arr");
   }
}

void binary(int *arr,int val){
    int low=0,high=sizeof(arr),mid=sizeof(arr)/2,i;
    while(low<high){
        if(val<arr[mid]){
            high=mid-1;
            mid=(low+high)/2;
        }
        else if(val>arr[mid]){
            low=mid+1;
            mid=(low+high)/2;
        }
        else{
            printf("value found at %d is %d",mid,val);
            break;
        }
    }
    if(low>high){
        printf("element not found ");
    }

}
void main(){
  int n,arr[10],i,val;
  printf("enter the number of elements:");
  scanf("%d",&n);
  printf("enter the elements:");
  for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  printf("enter the searching element:");
  scanf("%d",&val);
  linear(arr,val,n);
}
//   binary(arr,val);