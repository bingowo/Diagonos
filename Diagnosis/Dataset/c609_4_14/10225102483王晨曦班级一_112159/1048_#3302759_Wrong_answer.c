#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 66

typedef struct
{
    int cnt,v[N];
}BIGINT;

BIGINT transtoBIG(int x)
{
    BIGINT R={0,{0}};
    do
    {
        R.v[R.cnt++]=x%10;
        x/=10;
    }
    while(x>0);
    return R;
}

int bn(int x,int y)
{
    if(x>y) return x;
    else if(x<=y) return y;
}

BIGINT add(BIGINT a,BIGINT b)
{
    BIGINT c={0,{0}};
    int count=bn(a.cnt,b.cnt);

    for(int i=0;i<count;i++)
    {
        c.v[i]=a.v[i]+b.v[i];
        if(c.v[i]>=10)
        {
            c.v[i]-=10;
            c.v[i+1]++;
        }
    }

    if(c.v[count]!=0) c.cnt=count+1;
    else c.cnt=count;

    return c;
}

BIGINT cal(BIGINT n,int x)
{
    BIGINT arr[121];

    arr[0].cnt=1;
    arr[1].cnt=1;
    arr[2].cnt=1;
    arr[0].v[0]=0;
    arr[1].v[0]=1;
    arr[2].v[0]=1;

    for(int i=3;i<(x+1);i++)
        arr[i]=add(arr[i-1],arr[i-2]);

    return arr[x];
}

int main()
{
    int T;  scanf("%d\n",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",i);

        BIGINT big=transtoBIG(n);
        BIGINT c=cal(big,n);

        for(int k=c.cnt-1;k>=0;k--)
            printf("%d",c.v[k]);
        printf("\n");
    }
    return 0;
}



