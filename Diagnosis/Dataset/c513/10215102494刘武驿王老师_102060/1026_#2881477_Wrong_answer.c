#include<stdio.h>
#include<stdlib.h>
int cmp(void*a,void*b)
{
    return (int*)a-(int*)b;
}
int main()
{
    int n,s[100000];
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&s[i]);
    qsort(s,n,sizeof(int),cmp);
    long long int sum=0;
    for(int i=0;i<n/2;i++)
    {
        sum+=s[i+n/2]-s[n/2-1-i];
    }
    printf("%lld",sum);
}