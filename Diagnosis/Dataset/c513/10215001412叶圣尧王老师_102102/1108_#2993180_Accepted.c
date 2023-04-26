#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int val(int k1,int a[],int k2,int d[],int len)
{
    int i;
    for(i=0;i<=len;i++)
    {
        if(k2==d[i]&&k1==a[i])return i;
    }
    return 0;
}

int main()
{
    int T;scanf("%d",&T);
    for(int e=0;e<T;e++)
    {
        printf("case #%d:\n",e);
        int i,j,flag=0;int n,m;int a[1001],d[1001];
        scanf("%d %d",&n,&m);
        a[0]=n/m;d[0]=n%m;
        for(i=1;flag==0&&d[i-1]!=0;i++)
        {
            int t=d[i-1]*10;
            a[i]=t/m;
            d[i]=t%m;
            flag=val(a[i],a,d[i],d,i-1);
        }
        if(flag!=0)
        {
            for(j=0;j<i-1;j++)
            {
                printf("%d",a[j]);
                if(j==0&&i>1)printf(".");
            }
            printf("\n");
            printf("%d-%d\n",flag,i-2);

        }
        else
        {
            for(j=0;j<i;j++)
            {
                printf("%d",a[j]);
                if(j==0&&i>1)printf(".");
            }
            printf("\n");
        }
    }
}