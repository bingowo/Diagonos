#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findSame(char *s, int i){
    for(int k=0; k<i; ++k) {
        if(s[k] == s[i])
            return k;
    }
    return -1;
}

long long decode(int *num, int len, int R) {
    long long ans = 0;
    for(int i=0; i<len; ++i) {
        ans = ans*R + num[i];
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        printf("case #%d:\n",j);
        char s[61];
        scanf("%s",s);
        int num[61], k = 1;
        for(int t=0; s[t]; ++t) {
            int i = findSame(s,t);
            if(i != -1) {
                num[t] = num[i];
            }else {
                num[t] = k;
                if(k == 1) k = 0;
                else if(k == 0) k = 2;
                else ++k;
            }
        }
        if(k == 0) k = 2;
        printf("%lld\n",decode(num,strlen(s),k));
    }
    return 0;
}
