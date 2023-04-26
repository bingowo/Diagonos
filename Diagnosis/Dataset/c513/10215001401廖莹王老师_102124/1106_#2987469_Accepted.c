#include <stdio.h>
#include <stdlib.h>
#define N 1000000007
int main()
{
    char s[1000]={0};
    char re[10000]={0};
    int sum=1;
    long long p[1500];
    scanf("%s",s);
    int i=0,j=strlen(s);
    for(i=0;i<j;i++)
    {
        if(i==0){p[0]=1;if(s[0]!=s[1]&& s[1])p[0]=2;}
        else if(i==j-1){p[i]=1;if(s[i]!=s[i-1])p[i]=2;}
        else
        {
            p[i]=1;
            if(s[i]!=s[i-1] && s[i]!=s[i+1]){if(s[i-1]!=s[i+1])p[i]=p[i]+2;else p[i]++;}
            else if(s[i]!=s[i+1])p[i]++;
            else if (s[i]!=s[i-1])p[i]++;
        }
    }
    for(i=0;i<j;i++)
    {
        sum=((sum%N)*p[i])%N;
    }
    printf("%d\n",sum);
    return 0;
}

