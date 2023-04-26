#include<stdio.h>
#include<stdlib.h>
int cmp(const void*p1,const void*p2)
{
    int a=*((int *)p1);
    int b=*((int *)p2);
    return a-b;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[100001];
    for(int i=0;i<n;i++)
    scanf("%d",a+i);
    qsort(a,n,sizeof(int),cmp);
    long long s=0;
    for(int i=0;i<n;i+=2){
        s+=a[i+1]-a[i];
    }
    printf("%lld",s);
    return 0;
}