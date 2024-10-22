#include<stdio.h>
void main(){
    int a[3][3] ,i,j,m,left=0,right=0;
    printf("enter the size of arr:\n",m);
    scanf("%d",&m);
    printf("enter the element:\n");
    int l=m;
    for (i=0;i<m;i++){
        for(j=0;j<m;j++){
            scanf("%d",&a[i][j]);
            if(i==j){
                left+=a[i][j];
            }
            if(j==l-1){
                right+=a[i][l];
                l--;
            }
        }
    }
    printf("right %d",right);
    printf("left %d",left);

}