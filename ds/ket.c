#include<stdio.h>
void main(){
    int n,left=0,right=0;
    printf("enter size:");
    scanf("%d",&n);
    int arr[n][n],i ,j;
    printf("enter elements:\n");
    for ( i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d",&arr[i][j]);
        }
        
    }
    int l=n;
    printf("elements :\n");
    for ( i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d  ",arr[i][j]);
            if(i==j){
                left+=arr[i][j];
            }
            if(j==l-1){
                right+=arr[i][l];
                l--;
            }
        }
        printf("\n");
    }
     printf("right %d\n",right);
    printf("left %d\n",left);
}