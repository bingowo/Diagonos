#include <stdio.h>
#include <string.h>

int main()
{
    char S[100001];
    gets(S);
    char *p1=S;
    char *p2=S;
    long long int sum=0;
    while(*p2)
    {
        while(*p2!='0'&&*(p2+1)!='x')
        {
            p2++;
        }
        p2=p2+2;
        while(*p2)
        {
            if(*p2=='0'&&*(p2+1)=='x')
                break;
            if(*p2>='0'&&*p2<='9')
            {
               sum=sum*16+*p2-'0';
               p2++;
            }
            else if(*p2>='a'&&*p2<='f')
            {
                sum=sum*16+*p2-'a'+10;
                p2++;
            }
            else p2++;
        }
        if(sum==0)
        {
            printf("-1");
        }
        else if(*p2=='\0')
        printf("%lld",sum);
        else
            printf("%lld ",sum);
        sum=0;
    }
}
