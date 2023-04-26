#include<stdio.h>
int num[1001];
int main()
{
    int T,N,i,j,k=0;
    for(i=1;i<=1000;i++)
    {
        if(i%5==0)
        {
            j=i;
            while(j%5==0&&j!=0)
            {
                j=j/5;
                k++;
            }
        }
        num[i]=k;
    }
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&N);
        printf("case #%d:\n%d\n",i,num[N]);
    }
    return 0;
}