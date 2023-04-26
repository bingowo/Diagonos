#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d",&n);
    char s[100000][100];
    long long int sum=0;
    for(int i=0;i<n;i++)
    {
        scanf("%s",s[i]);
        sum+=strlen(s[i]);
    }
    sum/=n;
    long long int step=0;
    for(int i=0;i<n;i++)
    {
        long long int tmp=sum-strlen(s[i]);
        if(tmp<0) tmp=-tmp;
        step+=tmp;
    }
    printf("%lld",step);
}