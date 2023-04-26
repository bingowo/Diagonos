#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    int i=*(int*)a,j=*(int*)b;
    int cnt1=0,cnt2=0;
    while(i)
    {
        cnt1++;
        i/=10;
    }
    while(j)
    {
        cnt2++;
        j/=10;
    }
    if(cnt1>cnt2)
    {
        return -1;
    }
    else if(cnt1<cnt2)
    {
        return 1;
    }
    else
    {
        return *(int*)a-*(int*)b;
    }
}
int a[1000000];
int main()
{
    int k=0;
    while(scanf("%d",&a[k])!=EOF)
    {
        k++;
    }
    qsort(a,k,sizeof(a[0]),cmp);
    for(int i=0;i<k;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
