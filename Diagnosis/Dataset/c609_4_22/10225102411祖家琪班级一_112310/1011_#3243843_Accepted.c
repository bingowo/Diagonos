#include <stdio.h>
#include <string.h>
int main()
{
    char s[31];
    scanf("%s",s);
    int flag = 0,cnt = 0;
    long long a = 0,b = 0,c = 1;
    int l = strlen(s);
    if(strchr(s,'.') != NULL){
    while(s[cnt] != '.'){
        a *= 3;
        a += (s[cnt] < '2')?(s[cnt]-'0'):-1;
        cnt++;
    }
    cnt++;
    while(cnt < l){
        b *= 3;
        b += (s[cnt] < '2')?s[cnt]-'0':-1;
        c *= 3;
        cnt++;
    }
    if(a < 0){
        a++;
        b = c - b;
    }
    if(b < 0 && a != 0){
        b += c;
        a--;
    }
    if(a != 0) printf("%lld %lld %lld",a,b,c);
    else printf("%lld %lld",b,c);
    return 0;
    }
    while(cnt < l){
        a *= 3;
        a += (s[cnt] < '2')?(s[cnt]-'0'):-1;
        cnt++;
    }
    printf("%lld",a);
    return 0;
}
