#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100001] = {0};
    unsigned int d = 0;
    scanf("%s", s);
    int flag = 0;
    char* p = strstr(s,"0x");
    if(p == NULL)
    {
        printf("-1");
    }
    else
    {
        do
        {
            if((*(p+2) >='0' && *(p+2) <= '9')||(*(p+2)>='a' && *(p+2)<='f'))
            {
                flag = 1;
                p = p+2;
                if(*p <='9') d = *p - '0';
                else d = *p - 'a' + 10;
                p++;
                while((*p >='0' && *p <= '9')||(*p>='a' && *p<='f'))
                {
                    if(*p <='9') d = d*16 + *p - '0';
                    else d = d*16 + *p - 'a' + 10;
                    p++;
                }
                printf("%u ",d);
            }
            else p = p+2;
            p = strstr(p, "0x");
        }
        while(p != NULL);
        if(flag == 0) printf("-1");
    }

    return 0;
}
