#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void*a,const void *b)
{
    int x=*(int*)a;
    int y=*(int*)b;
    return x-y;
}
int a[1005]={0},b[1005];
int main()
{
    int i,n,s,max;
    scanf("%d %d",&n,&s);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    qsort(a+1,n,sizeof(int),cmp);
    a[n+1]=10000000;
    max=a[1];
    for(i=1; i<=n; i++)
        b[i]=b[i-1]+a[i];
    i=2;
    while(s>=(i-1)*a[i]-b[i-1])
    {   max=a[i];
        i++;

    }
    i--;
    s=s-(i-1)*a[i]+b[i-1];
    max=max+s/i;
    s=s%i;
    if(s==0)
        printf("%d",max);
    else
    {
        int j=2;
        while(j<=s)
        {
            if(s%j==0&&i%j==0)
            {
                s=s/j;
                i=i/j;
            }
            else
                j++;
        }
            printf("%d+%d/%d",max,s,i);
    }
    return 0;
}
