#include <stdio.h>
#include <stdlib.h>
int main()
{
    char s[100];
    scanf("%s",s);
    int i = 0;
    double ret1 = 0,ret2 = 0;
    while(s[i++]){
        if(s[i-1]!='.'){
            ret1 = ret1 * 3 + (s[i-1] - '1');
        }
        else{
            break;
        }
    int r = 1.0/3;
    while(s[i++]){
        ret2 = ret2 + (s[i-1]-'1') * r;
        r = r/3;
    }
    printf("%lf",ret1+ret2);
    return 0;
}
