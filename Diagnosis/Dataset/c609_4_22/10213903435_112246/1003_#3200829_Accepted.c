#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,i=0;
    long long arr[300];
    int rslt[300][20];
    scanf("%d",&t);
    while(i<t)scanf("%lld",arr+(i++));
    for(i=0;i<t;i++)
    {
        long long n=*(arr+i);
        int j=0;
        do
        {
            rslt[i][j++]=(int)(n%2333);
            rslt[i][j]=-1;
        }while(n/=2333);
    }
    for(i=0;i<t;i++)
    {
        int j=0;
        while(rslt[i][++j]>=0);
        while(j-->0){printf("%d ",*(*(rslt+i)+j));}
        printf("\n");
    }
    return 0;
}
