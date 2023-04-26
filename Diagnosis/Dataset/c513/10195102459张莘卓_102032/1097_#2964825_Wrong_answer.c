#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int cmp(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

int main()
{
    char s[81];
    while(scanf("%s",s) != EOF) {
        int row[80] = {0},rank[80] = {0};
        int sign[160] = {0}, cnt = 1;
        for(int i=1; s[i]; ++i) {
            if(s[i] > s[i-1]) row[i] = row[i-1] + 1;
            else if(s[i] < s[i-1]) row[i] = row[i-1] - 1;
            else row[i] = row[i-1];
            if(sign[row[i]+80] == 0) {
                sign[row[i]+80] = 1;
                rank[cnt++] = row[i];
            }
        }
        qsort(rank, cnt, sizeof(rank[0]), cmp);
        for(int j=0; j<cnt; ++j) {
            int target = rank[j], pre = -1;
            int i = 0;
            while(i < strlen(s)) {
                if(row[i] == target) {
                    for(int t=0; t<i-pre-1; ++t) printf(" ");
                    printf("%c",s[i]);
                    pre = i;
                }
                ++i;
            }
            printf("\n");
        }
    }
    return 0;
}
