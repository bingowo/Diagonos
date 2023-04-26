#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void*a,const void* b)
{
    return *(int*)b-*(int*)a;
}
int main()
{
    int *a,sum=0,n,w[11];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&w[i]);
        sum=sum+w[i];
    }
    a=(int*)malloc((sum+1)*sizeof(int));
    for(int i=1;i<=sum;i++)
        a[i]=0;
    qsort(w,n,sizeof(a[0]),cmp);
    for(int i=0;i<n;i++)
    {
        if(a[w[i]]==0) a[w[i]]=-1;
        for(int j=1;j<=sum;j++)
        {
            if(a[j]==1)
            {
                if(j-w[i]>0)
                    a[j-w[i]]=-1;
                if(j+w[i]<=sum)
                    a[j+w[i]]=-1;
            }
        }
        for(int j=1;j<=sum;j++)
        {
            if(a[j]==-1)
            {
                a[j]=1;
            }
        }

    }
    for(int i=1;i<=sum;i++)
        printf("%d",a[i]);
    return 0;
}
