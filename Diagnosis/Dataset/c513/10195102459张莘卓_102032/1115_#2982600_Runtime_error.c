#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int* a, int* b) {
    int t = *a; *a = *b; *b = t;
}

int cmp(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0; t<T; ++t) {
        char s[22];
        scanf("%s",s);
        int i, k, len = strlen(s), num[21] = {0};
        for(i=0; i<len; ++i) num[i] = s[len-1-i] - '0';
        for(i=1; i<len; ++i) {
            int min = 10;
            for(int j=i-1; j>=0; --j)
                if(num[j]>num[i] && num[j]<min) {
                    min = num[j];
                    k = j;
                }
            if(min < 10) break;
        }
        swap(&num[i], &num[k]);
        qsort(num, i, sizeof(int), cmp);
        printf("case #%d:\n",t);
        for(i=len-1; i>=0; --i) printf("%d",num[i]);
        printf("\n");
    }
    return 0;
}
