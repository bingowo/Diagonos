#include <stdio.h>
#include <string.h>
#define N 1000000007
int main()
{
    char s[1001];
    int L[1000];
    scanf("%s",s);
    int len=strlen(s),num=1;
    for(int i=1;i<len-1;i++)
    {
        if(s[i]!=s[i-1]) num++;
        if(s[i]!=s[i+1]) num++;
        L[i]=num;
        num=1;
    }
    if(s[0]!=s[1]) L[0]=2;
    else L[0]=1;
    if(s[len-1]!=s[len-2]) L[len-1]=2;
    else L[len-1]=1;
    long long int res=L[0];
    for(int i=1;i<len;i++)
    {
        res=(res*(L[i]%N))%N;
    }
    if(len==1) res=1;
    printf("%lld",res);
    return 0;
}