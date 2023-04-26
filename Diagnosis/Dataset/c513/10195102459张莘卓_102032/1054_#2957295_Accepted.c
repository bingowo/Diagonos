#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getString(char (*s)[36]) {
    char line[2001];
    getchar();
    gets(line);
    int i = 0, k = 0;
    while(line[i] == ' ') ++i;
    while(i < strlen(line)) {
        int index = 0;
        char word[36];
        while(line[i] && line[i] != ' ')
            word[index++] = line[i++];
        while(line[i] == ' ') ++i;
        word[index] = '\0';
        strcpy(s[k++], word);
    }
    return k;
}

int main()
{
    int T, M;
    scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        scanf("%d",&M);
        char s[1010][36];
        int len = getString(s), start = 0;
        printf("case #%d:\n",j);
        while(start < len) {
            int sum = 0, cnt = 0;
            while(start+cnt<len && sum+strlen(s[start+cnt]) < M) {
                sum += strlen(s[start+cnt]);
                if(cnt++) ++sum;
            }
            int space = M - sum + cnt - 1;
            for(int i=0; i<cnt; ++i) {
                printf("%s",s[start+i]);
                if(i == cnt-1) break;
                if(start + cnt == len) printf(" ");
                else{
                    for(int k=0; k<space/(cnt-1-i); ++k) printf(" ");
                    space -= space / (cnt-1-i);
                }
            }
            start += cnt;
            printf("\n");
        }
    }
    return 0;
}
