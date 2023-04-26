#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
char num[10][6] = {"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};

void eraser(int *a, int k, int cnt) {
    for(int i=0; num[k][i]; ++i)
        a[num[k][i]] -= cnt;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        char s[21];
        scanf("%s",s);
        int a[100] = {0}, cnt[10] = {0};
        for(int i=0; s[i]; ++i) ++a[s[i]];
        cnt[0]=a['Z']; cnt[2]=a['W']; cnt[4]=a['U'];
        cnt[6]=a['X']; cnt[8]=a['G'];
        for(int i=0; i<10; i+=2) eraser(a, i, cnt[i]);
        cnt[1] = a['O']; cnt[3] = a['H'];
        cnt[5] = a['F']; cnt[7] = a['S'];
        cnt[9] = a['I'] - cnt[5];
        printf("case #%d:\n",j);
        for(int k=0; k<10; ++k) {
            for(int i=0; i<cnt[k]; ++i)
                printf("%d",k);
        }
        printf("\n");
    }
    return 0;
}
