#include <stdio.h>

int main(void)
{
    char s[40];
    scanf("%s", s);
    long long int i = 0, n= 0, d= 1;
    char *p = s;
    while(*p != '.' && *p){
        i= i * 3;
        if(*p == '1'){
            i += 1;
        }else if(*p == '2'){
            i -= 1;
        }
        p ++;
    }
    if(*p){
        p ++;
    }
    while(*p){
        d *= 3;
        n *= 3;
        if(*p == '1'){
            n+= 1;
        }else if(*p == '2'){
            n-= 1;
        }
        p ++;
    }
    if(n== 0){
        printf("%lld", i);
    }else if(n> 0){
        if(i< 0){
            i ++;
            n = d - n;
        }
        if(i == 0){
            printf("%lld %lld", n, d);
        }else{
            printf("%lld %lld %lld", i, n, d);
        }
    }else if(n < 0){
        if(i > 0){
            i --;
            n= d+n;
        }
        if(i== 0){
            printf("%lld %lld", n,d);
        }else {
            printf("%lld %lld %lld", i,n,d);
        }
    }
    return 0;
}
