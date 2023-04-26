#include <stdio.h>
#include <stdlib.h>
int p[150];
void jisuan(int k,int n)
{
    int i=0;
    if(n>=3)
    {
        for(i=1;i<=k;i++)
    {
        if(n-i>0)
        {
        if(p[n-i]==-1)jisuan(k,n-i);
        p[n]=p[n]+p[n-i];
        }
        else break;
    }
    p[n]=p[n]+1;

    }
    return;
}
int main()
{
    int k=0,n=0,i=0;
    for(i=0;i<150;i++)p[i]=-1;
    scanf("%d %d",&k,&n);
    p[0]=0;p[1]=0;p[2]=1;
    jisuan(k,n);
    printf("%d",p[n]);
    return 0;
}
