#include <stdio.h>
#include <string.h>

void itob(unsigned n, char s[])
{
    int i;
    for(i = 98; n && i; n /= 2){
        s[i--] = (((n % 2) < 10) ? '0' : ('A' - 10)) + (n % 2);
    }
    memmove(s , s + i + 1, 99 - i- 1);
    s[99 - i- 1] = '\0';
}

void P(char s[], int length)
{
    int len = strlen(s);
    if(len < length){
        for(int i = 0; i < (length - len); i ++){
            printf("0");
        }
    }
    printf("%s", s);
}

int main(void)
{
    char s[501], temp[100];
    scanf("%s", s);
    int tm = 0, len = strlen(s);
    itob(len, temp);
    printf("0001");
    P(temp, 10);
    for(int i = 0 ; i < len; i ++){
        tm = tm * 10 + (s[i] - '0');
        if(i % 3 == 2){
            itob(tm, temp);
            P(temp, 10);
            tm = 0;
        }
    }
    if(len % 3 == 1){
        itob(tm, temp);
        P(temp, 4);
        tm = 0;
    }else if(len % 3 == 2){
        itob(tm, temp);
        P(temp, 7);
        tm = 0;
    }

    return 0;
}
