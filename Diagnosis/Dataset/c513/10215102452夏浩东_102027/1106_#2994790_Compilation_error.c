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
       for(int i=1;i<len-1;i++)
        {
            if(s[i]!=s[i-1]) num++;
            if(s[i]!=s[i+1]) num++;
            a[i]=num;
            num=1;
        }
        if(s[0]!=s[1]) a[0]=2;
        else a[0]=1;
        if(s[len-1]!=s[len-2]) a[len-1]=2;
        else a[len-1]=1;
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