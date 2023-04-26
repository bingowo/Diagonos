#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[1010]={0};
    scanf("%s",s);
    long long n=1,i;
    if (strlen(s)==1)
        printf("1\n");
    else if (strlen(s)>1)
        for (i=0;i<strlen(s);i++)
        {
            if (i==0)
                if (s[i]!=s[i+1])
                    n*=2;
            if (i>0 && i<strlen(s)-1)
            {
                if (s[i]!=s[i-1] && s[i]!=s[i+1] && s[i-1]!=s[i+1])
                    n*=3;
                else if (s[i]==s[i-1] && s[i]!=s[i+1])
                    n*=2;
                else if (s[i]==s[i+1] && s[i-1]!=s[i])
                    n*=2;
                else if (s[i-1]==s[i+1] && s[i-1]!=s[i])
                    n*=2;
            }
            if (i==strlen(s)-1)
                if (s[i]!=s[i-1])
                    n*=2;
        }
    printf("%lld\n",n);
    return 0;
}
