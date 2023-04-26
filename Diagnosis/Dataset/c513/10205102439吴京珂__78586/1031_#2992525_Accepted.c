#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp1(const void *a1,const void *b1)
{
    int a=*(int*)a1;
    int b=*(int*)b1;
    if(a!=b) return a-b;
}

int cmp2(const void *a1,const void *b1)
{
    int a=*(int*)a1;
    int b=*(int*)b1;
    if(a!=b) return b-a;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        int a[1005]={0},b[1005]={0};
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[j]);
        }
        for(int j=0;j<n;j++)
        {
            scanf("%d",&b[j]);
        }

        qsort(a,n,sizeof(a[0]),cmp1);
        qsort(b,n,sizeof(b[0]),cmp2);
        int ans=0;
        for(int j=0;j<n;j++)
        {
            ans+=a[j]*b[j];
        }
        printf("case #%d:\n",i);
        printf("%d\n",ans);
    }
    return 0;
}



