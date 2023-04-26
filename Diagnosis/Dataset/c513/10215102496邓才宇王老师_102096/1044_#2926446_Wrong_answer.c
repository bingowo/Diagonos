#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    char s[100001];
    gets(s);
    char *p=s;
    int flag=0;
    while(*p)
    {
        if(*p=='0'&&*(p+1)=='x')
        {
            p+=2;
            long long int count=0;
            int f=0;
            while((*p>='0'&&*p<='9')||(*p>='a'&&*p<='f'))
            {
                f=1;
                int num=0;
                if(*p>='a'&&*p<='f') num=*p-'a'+10;
                else num=*p-'0';
                count=count*16+num;
                p++;
            }
            if(f==1)
            printf("%lld ",count);
            flag=1;
        }
        else p++;
    }
    if(flag==0) printf("%d ",-1);
}
