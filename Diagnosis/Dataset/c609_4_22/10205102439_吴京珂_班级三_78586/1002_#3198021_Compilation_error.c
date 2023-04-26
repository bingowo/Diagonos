#include <stdio.h>
#include <stdlib.h>

void _2(int n)
{
    int ans=0;
    int d=-1;//
    int a=0;
    while(n!=0)
    {
        if((n&1)!=d)//最后一位
        {
            a++;
            if(ans<a) ans=a;
        }
        else
        {
            a=1;
        }

        d=n&1;

        n=n>>1;//右移
    }

    printf("case #%d:\n",i);
    printf("%d\n",ans);
}

int main()
{
    int T;
    scanf("%d",&T);

    for(int i=0; i<T; i++)
    {
        int n;
        scanf("%d",&n);

        _2(n);
    }
    return 0;
}
