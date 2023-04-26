#include <stdio.h>
#include <string.h>

void itob(int n, char s[])
{
    int i;
    for(i = 98; n && i; n /= 2){
        s[i--] = (((n % 2) < 10) ? '0' : ('A' - 10)) + (n % 2);
    }
    memmove(s , s + i + 1, 99 - i- 1);
    s[99 - i- 1] = '\0';
}

int compare(char s1[], char s2[])
{
    int offset = strlen(s1) - strlen(s2);
    int ret = 0;
    for(int i = 0; i < offset; i ++){
        if(s1[i] != '0'){
            ret ++;
        }
    }
    for(int i = 0; s2[i]; i ++){
        if(s1[i + offset] != s2[i]){
            ret ++;
        }
    }

    return ret;
}

int main(void)
{
    int t;
    scanf("%d", &t);
    for(int i = 0 ; i < t; i ++){
        int x, y;
        scanf("%d %d", &x, &y);
        char str_x[100], str_y[100];
        itob(x, str_x), itob(y, str_y);
        int cnt = 0;
        if(strlen(str_x) > strlen(str_y)){
            cnt = compare(str_x, str_y);
        }else{
            cnt = compare(str_y, str_x);
        }
        printf("%d\n", cnt);
    }

    return 0;
}