#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    return *((int *)a)-*((int *)b);
}
int main()
{
    long long int n,sum=0;
    long long int s[100000];
    scanf("%lld",&n);
    for(int i=0;i<n;i++) scanf("%lld ",&s[i]);
    int len=strlen(s);
    qsort(s,len,sizeof(s[0]),cmp);
    for(int i=0;i<n;i+=2)
    {
        sum=sum+s[i+1]-s[i];
    }
    printf("%lld",sum);
    return 0;
}
