#include <stdio.h>
#include <string.h>

int findRepeat(int* a, int end, int len){
    for(int i=len-2; i>=end; --i)
        if(a[i] == a[i+1]) return i;
    return -1;
}

void plus1(int* a, int index, int* plen) {\
    int carry = 1;
    for(int i=index; i<*plen; ++i) {
        a[i] += carry;
        carry = a[i] / 10;
        a[i] %= 10;
        if(carry == 0) break;
    }
    if(carry) a[(*plen)++] = carry;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        char s[101];
        scanf("%s",s);
        int len = strlen(s), a[111] = {0};
        for(int i=0; i<len; ++i) a[i] = s[len-1-i] - '0';
        int k = 0, start = 0;
        do{
            plus1(a, k, &len);
            while(start < k) a[start++] = 0;
            while(a[start] == 0) ++start;
        }while((k = findRepeat(a, start, len)) != -1);
        for(int i=start-1; i>=0; --i)
            a[i] = a[i+1] ? 0 : 1;
        for(k=110; a[k]==0; --k);
        printf("case #%d:\n",j);
        for(; k>=0; --k) printf("%d",a[k]);
        printf("\n");
    }
    return 0;
}
