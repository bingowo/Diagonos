#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int wei;
    int a[100];
}bigint;

long long co[510];

long long sum(int n)
{
    if(n==1) {co[n]=1;return 1;}
    else if(n==2) {co[n]=2;return 2;}
    else if(n==3) {co[n]=3;return 3;}
    else if(n==4) {co[n]=6;return 6;}
    else
    {
        if(co[n-1]==0) co[n-1]=sum(n-1);
        if(co[n-2]==0) co[n-2]=sum(n-2);
        if(co[n-4]==0) co[n-4]=sum(n-4);
        co[n]=co[n-1]+co[n-2]+co[n-4];
        return co[n];
    }

}

int main()
{
    int n;
    long long re;
    scanf("%d",&n);
    memset(co,0,sizeof(long long)*510);
    re=sum(n);
    printf("%lld",re);

}