#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
    int x=*(int*)a;
    int y=*(int*)b;
    return x-y;
}
int main()
{
    int m,n;
    int a[501];
    int b[501];
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&n);
    for(int j=0;j<n;j++)
    {
        scanf("%d",&b[j]);
    }
    qsort(b,n,sizeof(b[0]),cmp);
    int result[501];
    int index=0;
    for(int k=0;k<m;k++)
    {
        for(int h=0;h<n;h++)
        {
            if(a[k]==b[h])
            {
                result[index]=a[k];
                index++;
                b[h]=1001;
            }
        }
    }
    for(int t=0;t<n;t++)
    {
        if(b[t]<1001)
        {
            result[index]=b[t];
            index++;
        }
    }
    for(int x=0;x<index-1;x++)
        printf("%d ",result[x]);
    printf("%d",result[index-1]);
    return 0;
}
