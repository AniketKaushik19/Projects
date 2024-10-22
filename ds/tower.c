#include<stdio.h>

void tower(int n,char s[],char a[],char d[]){
   if(n==1){
    printf("disc %d move from %s to %s\n",n,s,d);
   }
   else{
    tower(n-1,s,d,a);
    printf("disc %d move from %s to %s\n",n,s,d);
    tower(n-1,a,s,d);
   }
}
void main(){
  tower(5,"source","auxillary","destination");
}