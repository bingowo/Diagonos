#include <stdio.h>
#include <stdlib.h>
long long int NUM[51];
int k;

long long int count(long long int a)
{
    long long int res=0;
    if(a==1){res=1;NUM[a-1]=res;}
    else if(a==2){res=2;NUM[a-1]=res;}
    else if(a==3){res=4;NUM[a-1]=res;}
    else if(a==4){res=8;NUM[a-1]=res;}
    else
    {
        if(NUM[a-2]!=-1){res=NUM[a-2]+NUM[a-3]+NUM[a-4]+NUM[a-5];NUM[a-1]=res;}
        else res=count(res-1)+count(res-2)+count(res-3)+count(res-4);
    }


    return res;
}

int main()
{
    for(k=0;k<51;k++)
    {
        NUM[k]=-1;
    }
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        long long int n;
        scanf("%lld",&n);
        long long int res=count(n);
        printf("case #%d:\n",i);
        printf("%lld\n",res);
    }
    return 0;
}
