#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp1(const void *a1,const void *b1)
{
    int a=*(int*)a1;
    int b=*(int*)b1;
    if(a!=b) return a-b;
}

int main()
{

    int n;
    scanf("%d",&n);
    int a[100005]= {0};
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }

    qsort(a,n,sizeof(a[0]),cmp1);
    int ans=0;
    for(int i=0; i<n; i+=2)
    {
        ans+=a[i+1]-a[i];
    }
    printf("%d\n",ans);

    return 0;
}



