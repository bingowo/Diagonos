#include <stdio.h>
#include <string.h>

void itob(unsigned n, char s[])
{
    int i;
    for(i = 98; n && i; n /= 2){
        s[i--] = (((n % 2) < 10) ? '0' : ('A'  - 10)) + (n % 2);
    }
    memmove(s , s + i+1 , 99 - i- 1);
    s[99 - i- 1] = '\0';
}

int main(void)
{
    int t;
    scanf("%d", &t);
    for(int i = 0 ; i < t ; i ++){
        unsigned int num;
        scanf("%u", &num);
        char s[100];
        itob(num, s);
        char *p1 = s, *p2 = s;
        int MaxLen = 1, len = 0;
        while(*p1 && *p2){
            p2 ++;
            if(*(p2 - 1) == *p2){
                len = p2 - p1;		//每当遇到相同的就结算一次长度 
                if(len > MaxLen){
                    MaxLen = len;
                }
                p1 = p2;
            }
        }
        
        printf("case #%d:\n", i);
        printf("%d\n", MaxLen);
    }

    return 0;
}

