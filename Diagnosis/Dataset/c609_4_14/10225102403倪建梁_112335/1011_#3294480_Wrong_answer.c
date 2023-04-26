#include <stdio.h>
int main() {
    char s[1000];
    scanf("%s", s);
    int i=0;
    long long a=0,b=0;
    for(;s[i] != '\0' && s[i] != '.';i++){
        a *= 3;
        if (s[i]=='2') a -= 1;
        else a = a + s[i] - '0';
    }//整数求值
    long long c=1;
    if(s[i]=='.'){
        i += 1;
        for(;s[i] != '\0' && s[i] != '.';i++){
        b *= 3;
        if (s[i]=='2') b -= 1;
        else b = b + s[i] - '0';//小数的分子求值
        c *= 3;//小数的分母求值
        }
        //处理处理整数小数部分符号不一致的问题
        if (a>0 && b<0){
            a -=1;b=c-b;
        }
        if (a<0 && b>0){
            a +=1;b=c-b;
        }
    }
        if (c == 1) printf("%lld",a);
        else {
            if(a != 0) printf("%lld %lld %lld",a,b,c);
            else printf("%lld %lld",b,c);
        }
    return 0;
}