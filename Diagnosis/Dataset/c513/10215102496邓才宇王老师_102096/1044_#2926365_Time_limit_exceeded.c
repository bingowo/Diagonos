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
            int count=0;
            while((*p>='0'&&*p<='9')||(*p>='a'&&*p<='f'))
            {
                int num=0;
                if(*p>='a'&&*p<='f') num=*p-'a'+10;
                else num=*p-'0';
                count=count*16+num;
                p++;
            }
            printf("%d ",count);
            flag=1;
        }
    }
    if(flag==0) printf("%d ",-1);
}
