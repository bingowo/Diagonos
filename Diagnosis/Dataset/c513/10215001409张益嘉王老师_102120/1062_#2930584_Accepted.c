#include <stdio.h>
#include <stdlib.h>

long long cun[60];

long long num(int n)
{
    //printf("n=%d\n",n);

    if(n==1) cun[n]=1;
    else if(n==2) cun[n]=2;
    else if(n==3) cun[n]=4;
    else if(n==4) cun[n]=8;
    else
    {
        if(cun[n-1]==-1) cun[n-1]=num(n-1);
        if(cun[n-2]==-1) cun[n-2]=num(n-2);
        if(cun[n-3]==-1) cun[n-3]=num(n-3);
        if(cun[n-4]==-1) cun[n-4]=num(n-4);

        cun[n]=cun[n-1]+cun[n-2]+cun[n-3]+cun[n-4];
    }

    return cun[n];

}

int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        long long re;
        memset(cun,-1,sizeof(long long)*60);
        //printf("re=%lld\n",re);
        re=num(n);
        printf("case #%d:\n%lld\n",i,re);

    }
    return 0;
}
