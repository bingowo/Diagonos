#include <stdio.h>
#include <string.h>
long long decimal(int* code,char* s,int r);
long long power(int r,int n);
int main()
{
    int T;
    long long ans;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char s[61];
        int code[128],r=2;
        for(int j=0;j<128;j++)  code[j]=-1;
        scanf("%s",s);
        code[s[0]]=1;
        code[s[1]]=0;
        for(int j=2;j<strlen(s);j++)
        {
            if(code[s[j]]==-1)
            {
                code[s[j]]=r++;
            }
        }
        ans=decimal(code,s,r);
        printf("case #%d:\n%lld\n",i,ans);

    }
}
long long decimal(int* code,char* s,int r)
{
    long long ans=0,temp;
    int n=0;
    for(int i=strlen(s)-1;i>-1;i--)
    {
        temp=power(r,n);
        n++;
        ans+=temp*code[s[i]];
    }
    return ans;
}
long long power(int r,int n)
{
    long long ans=1;
    while(n--)  ans*=r;
    return ans;
}