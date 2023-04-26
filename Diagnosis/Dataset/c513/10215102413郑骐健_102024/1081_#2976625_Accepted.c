#include <stdio.h>
#include <stdlib.h>
#define num
typedef struct{
        int cnt;
        int s[3000];
}bigint ;

bigint Big(int n)
{
    bigint res;
    memset(res.s,0,sizeof(res.s));
    int t =0;
    do
    {
        res.s[t++]=n%10;
        n/=10;
    }
    while(n>0);
    res.cnt=t;
    return res;
}
bigint mul(bigint p1,bigint p2)
{
    bigint res;
    memset(res.s,0,sizeof(res.s));
    res.cnt = p1.cnt+p2.cnt ;
    int i,z;
    for(i =0;i<p1.cnt;i++)
    {
        int carry=0;
        for(z =0;z<p2.cnt;z++)
        {
            int p =p1.s[i]*p2.s[z]+carry+res.s[i+z];
            res.s[i+z] = p%10;
            carry = p/10;
        }
        int  po = i+z;
        while(carry>0)
        {
            int n = res.s[po]+carry;
            res.s[po]=n%10;
            carry = n/10;
            po++;
        }
    }
    if(res.s[res.cnt-1]==0)res.cnt--;
    return res;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i =0;i<t;i++)
    {
        printf("case #%d:\n",i);
        int a;int n;
        scanf("%d%d",&a,&n);
        bigint k1 = Big(a);
        bigint res = Big(a);
        if(n==0)printf("1");
        else
        {
            for(int q =0;q<n-1;q++)
            {res =mul(res,k1);}
            for (int g=res.cnt-1;g>=0;g--)printf("%d",res.s[g]);

                    }
        if(i!=t-1)printf("\n");

    }

    return 0;
}
