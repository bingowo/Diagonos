#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    char s[100005];
    scanf("%s",s);
    unsigned int x=0;
    char* p=s;int flag=0,sign=0;
    while(*p!='\0')
    {
        p=strstr(p,"0x");
        if(p==NULL)
        {
            break;
        }
        else
        {
            p+=2;flag=1;
            while(isdigit(*p) || ((*p)>='a' &&(*p)<='f'))
            {
                sign=1;
                if(isdigit(*p))
                {
                    x=x*16+(*p-'0');
                }
                else
                {
                    x=x*16+(*p-'a'+10);
                }
                p++;
            }
            if(sign==1) printf("%u ",x);
            x=0;sign=0;
        }
    }
    if(flag==0) printf("-1");
    return 0;
}

