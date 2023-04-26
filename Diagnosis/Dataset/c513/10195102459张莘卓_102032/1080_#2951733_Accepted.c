#include <stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        int cnt, a[100] = {0}, binary[334] = {0};
        char s[101];  scanf("%s",s);
        for(cnt=0; s[cnt]; ++cnt) a[cnt] = s[cnt] - '0';
        int k = 0, start = 0, end = 0;
        while(start < cnt) {
            int mod = 0;
            for(int i=start; i<cnt; ++i) {
                int t = mod * 10 + a[i];
                a[i] = t / 2;
                mod = t % 2;
            }
            if(mod) end = k;
            binary[k++] = mod;
            while(start<cnt && a[start]==0) ++start;
        }
        int len = 1, ans[111] = {0};
        for(start=0; start<=end && binary[start]==0; ++start);
        for(int k=start; k<=end; ++k) {
            int carry = 0;
            for(int i=0; i<len; ++i) {
                int t = ans[i] * 2 + carry;
                carry = t / 10;
                ans[i] = t % 10;
            }
            if(carry) ans[len++] = carry;
            carry = 0;
            ans[0] += binary[k];
            for(int i=0; i<len; ++i) {
                carry = ans[i] / 10;
                ans[i] %= 10;
                if(carry == 0) break;
            }
            if(carry) ans[len++] = carry;
        }
        printf("case #%d:\n",j);
        for(len=110; len>=0 && ans[len]==0; --len);
        if(len < 0) printf("0");
        for(int i=len; i>=0; --i) printf("%d",ans[i]);
        printf("\n");
    }
    return 0;
}
