#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void itob(int n,char *s, int b)
{
    int i;
    n = abs(n);
    for(i = 98; n && i; n /= b){
        s[i --] = (((n % b) < 10) ? '0' : ('A' - 10)) + (n % b);
    }
    memmove(s, s + i + 1, 99 - i - 1);
    s[99 - i - 1] = '\0';
}

int main(void)
{
    int b1, b2;
    int n = 0, t = 0;
    char s[100], r[100];
    scanf("%d %s %d", &b1, s, &b2);
    char *p = s;
    if(*p == '0' && *(p + 1) == '\0'){
        printf("0");
    }else{
        while (*p){
            *p = toupper(*p);    //把字符串都转化为大写字母
            if(isdigit(*p)){
                t = *p - '0';
            }else{
                t = *p - 'A' + 10;
            }
            n = n * b1 + t;
            p ++;
        }
        itob(n, r, b2);
        printf("%s", r);
    }



    return 0;
}