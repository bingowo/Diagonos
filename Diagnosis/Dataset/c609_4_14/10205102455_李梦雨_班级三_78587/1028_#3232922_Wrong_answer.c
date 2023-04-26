#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b)
{
    int *s1,*s2;
    s1=(int *)a;
    s2=(int *)b;
    while(*s1!=-1&&*s2!=-1&&*s1==*s2)
    {
        s1++;
        s2++;
    }
    return *s2-*s1;
}

int main()
{
    int t;
    scanf("%d\n",&t);
    for(int k=0;k<t;k++)
    {
        int n;
        scanf("%d\n",&n);
        int a[1000][50];
        for(int i=0;i<n;i++)
        {
            int j=0;
            while(scanf("%d",&a[i][j])&&a[i][j]!=-1) j++;
        }
        qsort(a,n,sizeof(a[0]),cmp);
        for(int i=0;i<n;i++)
        {
            int j;
            for(j=0;a[i][j+1]!=-1;j++)
                printf("%d ",a[i][j]);
            printf("%d\n",a[i][j]);
        }
    }
    return 0;
}