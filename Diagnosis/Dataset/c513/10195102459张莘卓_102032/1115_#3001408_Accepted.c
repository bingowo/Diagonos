#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b)
{return *(int*)b - *(int*)a;}

int main()
{
    int T, num[22];
    scanf("%d",&T);
    char s[22];
    for(int t=0; t<T; ++t) {
        scanf("%s",s);
        int len = (int) strlen(s);
        for(int i=0; i<len; ++i)
            num[i] = s[len-1-i] - '0';
        int flag[22]={0};
        for(int i=0; i<len; ++i)
            for(int j=i+1; j<len; ++j) {
                if(num[j] < num[i]) {
                    if(flag[j]==0) flag[j] = num[i];
                    else flag[j] = flag[j]>num[i]?num[i]:flag[j];
                    break;
                }
            }
        printf("case #%d:\n",t);
        int k = 0;
        while(k<len && flag[k]==0) ++k;
        if(k < len) {
            for(int i=0; i<k; ++i)
                if(num[i] == flag[k]) {
                    num[i] = num[k];
                    num[k] = flag[k];
                }
            qsort(num, k, sizeof(int), cmp);
        }else {
            qsort(num, len, sizeof(int), cmp);
            int i = len - 1;
            while(num[i]==0) --i;
            printf("%d",num[i]);
            num[i] = 0;
        }
        for(int i=len-1; i>=0; --i) printf("%d",num[i]);
        printf("\n");
    }
    return 0;
}
