#include <stdio.h>
#include <string.h>
int main()
{
    char s[100001];
    char a[] = "0123456789abcdef";
    gets(s);
    unsigned int res = 0;
    char *b = strstr(s,"0x");
    if(b==NULL) printf("-1");
    else
    {
       int j,i = 2;
       while(b!=NULL)
       {i = 2;
       res = 0;
       while(1)
            {
                for(j = 0;j<strlen(a);j++)
                if(*(b+i)==a[j]) {res = res*16 + j;break;}
                if(j==strlen(a)) break;
                i++;
            }
            printf("%u ",res);
            b = strstr(b+i,"0x");
       }


    }
    return 0;
}
