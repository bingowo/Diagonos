#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100],t[400];
    scanf("%s", s);
    long long int a = 0,b = 0,pr,pi;
    int flag = 0;
    if(strchr(s,'+')){
        int i = 0;
        if(s[0] == '-'){
            flag = 1;
            i++;
        }
        for(;i < strchr(s,'+');i++){
            a = a * 10 + s[i] - '0';
        }
        i++
        for(;i < strlen(s) - 1;i++){
            b = b * 10 + s[i] - '0';
        }
    }else if(strchr(s,'i')){
        for(int i = 0;i < strlen(s) - 1;i++){
            b = b * 10 + s[i] - '0';
        }
    }else{
        for(int i = 0;i < strlen(s);i++){
            a = a * 10 + s[i] - '0';
        }
    }
    printf("%lld %lld",a,b)
    return 0;
}
