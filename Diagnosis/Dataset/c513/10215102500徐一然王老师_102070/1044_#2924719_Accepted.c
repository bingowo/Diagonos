#include <stdio.h>
#include <string.h>

int main()
{
    char S[100001];
    gets(S);
    int flag=0;
    char *p2=S;
    long long int sum=0;
    while(*p2)
    {
        while(*p2!='0'||*(p2+1)!='x')
        {
            p2++;
        }
        p2=p2+2;
        while(*p2)
        {
            if(*p2=='0'&&*(p2+1)=='x')
            {
                if(*(p2+2)=='\0');
                else if(*(p2+2)>'f');
                else break;
            }
            if(*p2>='0'&&*p2<='9')
            {
                flag=1;
               sum=sum*16+*p2-'0';
               p2++;
            }
            else if(*p2>='a'&&*p2<='f')
            {
                flag=1;
                sum=sum*16+*p2-'a'+10;
                p2++;
            }
            else
            {
                while((*p2!='0'||*(p2+1)!='x')&&*p2)
                {
                    p2++;
                }
                break;
            }
        }
        if(sum==0&&*p2=='\0'&&flag==0)
        {
            printf("-1");
        }
        else if(sum==0&&*p2=='\0'&&flag==1)
        {
            printf("0");
        }
        else if(sum==0&&flag==1)
        {
            printf("%lld ",sum);
        }
        else if(sum==0&&flag==0);
        else if(*p2=='\0')
        printf("%lld",sum);
        else
            printf("%lld ",sum);
        sum=0;
        flag=0;
    }
}
