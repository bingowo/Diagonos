#include <stdio.h>
#include <stdlib.h>
long int num[1000001],mid[1000001];

int cmp(const void* a,const void* b)
{
    long int d1,d2;
    int t;
    d1=*((long int*)a),d2=*((long int*)b);
    if(d1>d2) t=-1;
    else t=1;
    return t;
}

int main()
{
    int n,m;
    long int flag=0;
    scanf("%d %d",&n,&m);
    int i,j;
    for(i=0;i<n;i++)
        scanf("%ld",&num[i]);
    qsort(num,n,sizeof(num[0]),cmp);
    for(i=0;i<=n-m;i++)
    {
        mid[i]=0;
        for(j=i;j<i+m;j++)
            {
                mid[i]+=num[i]-num[j];
                if(i)
                    if(mid[i]>flag) break;
            }
        if(i==0) flag=mid[0];
        else if(j==i+m) flag=mid[i];
    }
    printf("%ld",flag);
    return 0;
}
