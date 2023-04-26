#include <stdio.h>
#include <string.h>
int main()
{
    char s[31];
    scanf("%s",s);
    int flag = 0,a = 0,b = 0,c = 1;
    int l = strlen(s);
    if(s[0] == '-') flag = 1;
    int cnt = (flag)?1:0;
    int k = (s[cnt] < '2')?(s[cnt]-'0'):-1;
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
    if(b < 0){
        b += c;
        a--;
    }
    printf("%d %d %d",a,b,c);
    return 0;
}
