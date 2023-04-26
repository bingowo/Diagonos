#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int T,n;
int out[1005],in[1005],num[1005];

int cmp(const void* a,const void* b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        for(int i=1;i<=100;i++)
            in[i]=out[i]=0;
        scanf("%d",&n);
        int f=0,a,b;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
            num[i]=a*1000+b;
        }
        qsort(num+1,n,sizeof(int),cmp);
        for(int i=1;i<=n;i++)
        {
            if(i!=1 && num[i]==num[i-1])
                continue;
            a=num[i]/1000;
            b=num[i]%1000;
            out[a]++;
            in[b]++;
            if(out[a]>1||out[a]&&in[a]||out[b]&&in[b])
                f=1;
        }
        if(f==1)
            puts("Poor dxw!");
        else
            puts("Lucky dxw!");
    }
    return 0;
}