#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    return b==0?a:gcd(b%a,a);
}

int cmp(const void*a, const void*b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        int c,cmt=0,cnt=0,a[1001]={0}, flag[1001]={0};
        for(int i=0;i<N;i++)
        {
           scanf("%d",&c);
           if(flag[c]==0) { a[cnt]=c; cnt++;}
        }
        qsort(a,cnt,sizeof(int),cmp);
        for(int i=0;i<cnt;i++)
        {
            for(int j=i+1;j<cnt;j++)
            {
                if(gcd(a[i],a[j])==1) cmt++;
            }
        }
        printf("case #%d:\n",i);
        printf("%d%c",cmt,i==T-1?' ':'\n');
    }
    return 0;
}
