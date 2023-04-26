#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[1100];
int cmp(const void* p,const void* q)
{
    int* a=(int*)p;
    int* b=(int*)q;
    return(*a - *b);
}
int main()
{
    int n,s;
    scanf("%d %d",&n,&s);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    a[n]=a[n-1]+1;
    int i=0;
    for(i=0;i<n;i++)
    {
        while(a[i]<a[i+1] && s>=(i+1))
        {
            for(int j=0;j<=i;j++)
            {
                a[j]++;s--;
                if(s==0) break;
            }
        }
        if(s==0) break;
        else if(s<(i+1))
        {
            if(a[i]!=a[i+1]) break;
        }
    }
    if(s==0) printf("%d",a[i]);
    else if(s>0)
    {
        printf("%d+",a[0]);
        printf("%d/%d",s,i+1);
    }
    return 0;
}
