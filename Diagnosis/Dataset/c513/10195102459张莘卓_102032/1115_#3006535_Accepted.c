#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b){
    return *(int*)b - *(int*)a;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0; t<T; ++t) {
        char s[22];
        scanf("%s",s);
        int len = (int)strlen(s);
        int num[22] = {0}, cnt=0;
        for(; s[len-1-cnt]; ++cnt)
            num[cnt] = s[len-1-cnt] - '0';
        int k = ++cnt;
        for(int i=0; i<cnt; ++i)
            for(int j=i+1; j<cnt; ++j)
                if(num[i]>num[j] && j<k) {
                    k = j;
                    break;
                }
        qsort(num, k, sizeof(int), cmp);
        for(int i=k-1; i>=0; --i) {
            if(num[i] > num[k]) {
                int t = num[i];
                num[i] = num[k];
                num[k] = t;
                break;
            }
        }
        int i = cnt-1;
        while(num[i] == 0) --i;
        printf("case #%d:\n",t);
        while(i >= 0) printf("%d",num[i--]);
        printf("\n");
    }
    return 0;
}
