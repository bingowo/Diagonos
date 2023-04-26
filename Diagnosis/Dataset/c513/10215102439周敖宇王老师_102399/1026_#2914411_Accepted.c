#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    int *pa=(int*)a,*pb=(int*)b;
    return *pa>*pb?1:-1;
}
int main()
{
    int n,i,j,ans=0;
    int num[100010];
    scanf("%d",&n);
    for(i=0;i<n;i++)  scanf("%d",&num[i]);
    qsort(num,n,sizeof(int),cmp);
    for(i=0;i<n;i+=2)
    ans+=num[i+1]-num[i];
    printf("%d",ans);
    return 0;
}