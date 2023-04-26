#include<stdio.h>
#include<string.h>
int main()
{
    char s[1001];
    scanf("%s",&s);
    int len=(int)strlen(s);
    int a[len];
    if(len==1) printf("1");
    else
    {
        if(s[0]==s[1]) a[0]=1;
        else a[0]=2;
        for(int i=1;i<len-1;i++)
        {
            if(s[i]==s[i-1]&&s[i]==s[i+1]) a[i]=1;
            else if(s[i]!=s[i-1]&&s[i]!=s[i+1]&&s[i-1]!=s[i+1]) a[i]=3;
            else a[i]=2;
        }
        if(s[len-2]==s[len-1]) a[len-1]=1;
        else a[len-1]=2;
        long long result=1;
        for(int i=0;i<len;i++)
        {
            result=result*a[i];
            while(result>=1000000007)
            {
                result=result-1000000007;
            }
        }
        printf("%lld",result);
    }
    return 0;
}