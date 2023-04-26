#include <stdio.h>
#include <stdlib.h>

unsigned long long cun[80];


unsigned long long taibo(int x)
{

    if(x==0) cun[x]=0;
    else if(x==1) cun[x]=1;
    else if(x==2) cun[x]=1;
    else
    {
        if(cun[x-1]==-1) taibo(x-1);
        if(cun[x-2]==-1) taibo(x-2);
        if(cun[x-3]==-1) taibo(x-3);
        cun[x]=cun[x-1]+cun[x-2]+cun[x-3];
    }
    return cun[x];
}


int main()
{
    int i,t;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        memset(cun,-1,sizeof(unsigned long long)*80);
        unsigned long long ans=taibo(n);
        printf("case #%d:\n%llu\n",i,ans);

    }
    return 0;
}
