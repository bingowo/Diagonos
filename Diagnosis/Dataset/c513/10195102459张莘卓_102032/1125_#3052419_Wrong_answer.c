#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ll long long

typedef struct {
    ll fz, fm;
}F;

void simplify(ll* pa, ll* pb) {
    ll a = *pa, b = *pb;
    while(b) {
        ll t=a%b; a=b; b=t;
    }
    *pa /= a;  *pb /= a;
}

F plus(F* pa, F* pb) {
    F f = {0, pa->fm*pb->fm};
    f.fz = pa->fz*pb->fm + pa->fm*pb->fz;
    simplify(&f.fz, &f.fm);
    return f;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        char s[17];
        scanf("%s",s);
        printf("case #%d:\n",j);
        if(strchr(s,'.') == NULL) {
            printf("%s\n",s);
            continue;
        }
        int i = 0;
        ll a = 0, b = 0, base = 1;
        while(isdigit(s[i])) 
            a = a*10 + s[i++] - '0';
        for(i=i+1; isdigit(s[i]); ++i) {
            b = b*10 + s[i] - '0';
            base *= 10;
        }
        simplify(&b, &base);
        if(s[i] != '[') {
            printf("%lld/%lld\n",a*base+b, base);
            continue;
        }
        F f1 = {b, base};
        b = 0, base = 1;
        for(i=i+1; s[i]!=']'; ++i) {
            b = b*10 + s[i] - '0';
            base *= 10;
        }
        --base;
        int len = strchr(s,'[')-strchr(s,'.')-1;
        for(i=0; i<len; ++i) base *= 10;
        simplify(&b, &base);
        F f2 = {b, base};
        F f = plus(&f1, &f2);
        printf("%lld/%lld\n",f.fz+a*f.fm, f.fm);
    }
    return 0;
}
