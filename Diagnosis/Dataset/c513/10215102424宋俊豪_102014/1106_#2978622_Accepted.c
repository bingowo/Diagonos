
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#define maxn 1000000007
int main()
{
    char s[1005];
    long long int t=1;
    scanf("%s",s);
    int len=strlen(s);
    int id=1;
    if(len==1)
        printf("1");
    else
    {
        for(int i=0; i<len; i++)
        {
            if(i==0)
            {
                if(s[i]!=s[i+1])
                    t=t*2;
            }
            else if(i==len-1)
            {
                if(s[i]!=s[i-1])
                    t=t*2%maxn;
            }
            else
            {
                if(s[i-1]!=s[i]&&s[i-1]!=s[i+1]&&s[i+1]!=s[i])
                    t=t*3%maxn;
                else if(s[i]==s[i-1]&&s[i]==s[i+1])
                    ;
                else
                    t=t*2%maxn;
            }
        }
      printf("%lld",t);
    }
    return 0;
}
