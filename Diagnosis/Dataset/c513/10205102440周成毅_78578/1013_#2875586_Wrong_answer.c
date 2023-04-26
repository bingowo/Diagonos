#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int gcd_1(int a, int b){
    return b == 0 ? a:gcd_1(b, a%b);
}

int main() {
    char s[51];
    scanf("%s", s);
    int len = strlen(s);
    int tag0 = 0, tag1 = 0, integer = 0;
    int zi=0,mu=1,cet=1;
    for (int i = 0; i < len; i++) {
        if (s[i] == '-') {
            tag0 = 1;
            continue;
        } else if (s[i] == '.') {
            tag1 = 1;
            continue;
        } else if (isdigit(s[i]) && tag1 == 0) {
            if (s[i] == '2')
                integer = integer * 3 - 1;
            else
                integer = integer * 3 + s[i] - '0';
        } else {
            if(s[i]=='2'){
                cet*=3;
                zi=zi*cet-mu;
                mu*=cet;
            } else{
                cet*=3;
                zi=zi*cet+mu*(s[i]-'0');
                mu*=cet;
            }
        }
    }
    int tmp= gcd_1(zi,mu);
    zi/= tmp;
    mu/= tmp;
    tmp=integer*mu+zi;
    integer=tmp/mu;
    zi=tmp-integer*mu;
    if(integer==0){
        if(zi==0)
            printf("0\n");
        else{
            if(tag0==1)
                printf("-%d %d\n",zi/ gcd_1(zi,mu),mu/ gcd_1(zi,mu));
            else
                printf("%d %d\n",zi/ gcd_1(zi,mu),mu/ gcd_1(zi,mu));
        }
    } else{
        if(tag0==1){
            if(zi!=0)
                printf("-%d %d %d\n",integer,abs(zi/ gcd_1(zi,mu)),abs(mu/ gcd_1(zi,mu)));
            else
                printf("-%d\n",integer);
        } else{
            if(zi!=0)
                printf("%d %d %d\n",integer,abs(zi/ gcd_1(zi,mu)),abs(mu/ gcd_1(zi,mu)));
            else
                printf("%d\n",integer);
        }
    }
    return 0;
}
