#include<stdio.h>
#include<stdlib.h>
int cmp1(const void*a,const void*b)
{
    int x=*(int*)a;
    int y=*(int*)b;
    return x<y?-1:1;
}
int cmp2(const void*a,const void*b)
{
    int x=*(int*)a;
    int y=*(int*)b;
    return x>y?-1:1;

}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        int a[n],b[n];
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[j]);
        }
        for(int j=0;j<n;j++)
        {
            scanf("%d",&b[j]);
        }
        qsort(a,n,sizeof(int),cmp1);
        qsort(b,n,sizeof(int),cmp2);
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
