#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long toInt(char *s) {
    long long ans = 0;
    for(int i=0; s[i] && s[i]!='.'; ++i) {
        int p = s[i] == '2' ? -1 : s[i]-'0';
        ans = ans * 3 + p;
    }
    return ans;
}

void save(long long *p1, long long *p2) {
    long long a = *p1, b = *p2;
    while(b) {
        long long t = a % b;
        a = b;
        b = t;
    }
    *p1 = (*p1) / a; *p2 = (*p2) / a;
}

int main()
{
    char s[31];
    scanf("%s",s);
    long long a = toInt(s);
    char *p = strchr(s, '.');
    if(p != NULL) {
        long long b = toInt(++p);
        long long c = 1;
        for(; *p; ++p) c *= 3;
        if(a>0 && b<0) {
            b += c;
            --a;
        }else if(a<0 && b>0){
            b = c - b;
            ++a;
            if(a==0) printf("-");
        }else if(a==0 && b<0) {
            b = -b;
            printf("-");
        }else if(b < 0) b = -b;
        save(&b, &c);
        if(a == 0) {
            printf("%lld %lld\n",b,c);
        }else {
            printf("%lld %lld %lld\n",a,b,c);
        }
    }else {
        printf("%lld\n",a);
    }
    return 0;
}

