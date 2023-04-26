#include <stdio.h>
#include <stdlib.h>
#define N 50000
int main()
{
    int t,arr[N][2];
    char rslt[N][100];
    int i=0,j=0;
    scanf("%d",&t);
    while(i++<t)
    {
        scanf("%d%d",arr[i],arr[i]+1);
        int n=arr[i][0],r=arr[i][1];
        if(n>0)
        do
        {
            rslt[i][j++]=r>10?(char)(n%r+55):(char)(n%r+'0');
        }while(n/=r);
        else if(n<0)
        do
        {
            rslt[i][j++]='-';
            rslt[i][j++]=r>=10?(char)(n%r+55):(char)(n%r+'0');
        }while(n/=r);
        rslt[i][j]=0;
    }
    i=0,j=0;
    for(;i<t;i++)
    {
        for(;rslt[i][j];j++)
        {
            printf("%c",rslt[i][j]);
        }
        printf("\n");
    }
    return 0;
}
