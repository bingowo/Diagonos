#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100];
    int t[400];
    scanf("%s", s);
    long long int a = 0,b = 0,qr,qi,r;
    int flag = 0;
    if(strchr(s,'+')){
        int i = 0;
        if(s[0] == '-'){
            flag = 1;
            i++;
        }
        for(;s[i] != '+';i++){
            a = a * 10 + s[i] - '0';
        }
        if(flag)a = -a;
        i++;
        for(;i < strlen(s) - 1;i++){
            b = b * 10 + s[i] - '0';
        }
    }else if(strchr(s + 1,'-')){
        int i = 0;
        if(s[0] == '-'){
            flag = 1;
            i++;
        }
        for(;s[i] != '-';i++){
            a = a * 10 + s[i] - '0';
        }
        if(flag)a = -a;
        i++;
        for(;i < strlen(s) - 1;i++){
            b = b * 10 + s[i] - '0';
        }
        b = -b;
    }else if(strchr(s,'i')){
        int i = 0;
        if(s[0] == '-'){
            flag = 1;
            i++;
        }
        for(;i < strlen(s) - 1;i++){
            b = b * 10 + s[i] - '0';
        }
        if(flag)b = -b;
    }else{
        int i = 0;
        if(s[0] == '-'){
            flag = 1;
            i++;
        }
        for(int i = 0;i < strlen(s);i++){
            a = a * 10 + s[i] - '0';
        }
        if(flag)a = -a;
    }
    int len = 0;
    while(b != 0 || a > 1){
        r = (a + b) % 2;
        if(r == -1)r = 1;
        t[len] = r;
        qr = (b - a +r)/2;
        qi = qr - b;
        a = qr;
        b = qi;
        len++;
    }
    if(a == 1){
        t[len] = 1;
        len++;
    }
    for(int i = len - 1;i >= 0;i--){
        printf("%d",t[i]);
    }
    return 0;
}
