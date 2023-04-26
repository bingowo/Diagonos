#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * itob(int num);

int main()
{
    char s[501];
    scanf("%s",&s);
    int len = strlen(s);
    char out[5000];
    char *p = out;
    int i;
    for(i = 0; i + 2 < len; i = i + 3){
        int num = (s[i] - '0') * 100 + (s[i + 1] - '0') * 10 + (s[ i + 2 ] - '0') * 1;
        strcpy(p, itob(num));
        p = p + 10;
    }
    if(len - i == 1){
        int num = s[len - i] - '0';
        strcpy(p,itob(num) + 6);
        p = p + 4;
    }else if(len - i == 2){
        int num = (s[len - 2] - '0') * 10 + (s[len - 1] - '0');
        strcpy(p,itob(num) + 3);
        p = p + 7;
    }
    *p = '\0';
    printf("0001%s%s\n", itob(len), out);
    return 0;
}

char * itob(int num){
    static char buf[11];
    int k = 9;
    do{
        buf[k--] = num % 2 + '0';
        num = num / 2;
    }while(num >= 0 && k >= 0);
    return buf;
}
