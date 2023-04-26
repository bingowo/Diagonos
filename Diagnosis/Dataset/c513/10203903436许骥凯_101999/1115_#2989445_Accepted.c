#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void *p1, const void *p2){
    return *(char *)p1 - *(char *)p2;
}

int main(){
    int n; scanf("%d", &n);
    for (int i = 0; i != n; i++){
        printf("case #%d:\n", i);
        char s[21]; scanf("%s", s);
        int slen = strlen(s);

        int flag = 0; 
        for (int i = 0; i != slen - 1; i++)
            if (s[i] < s[i+1]){
                flag = 1; break;
            }
        if (!flag){
            for (int i = slen; i >= 1; i--)
                s[i] = s[i-1];
            s[0] = '0'; s[++slen] = 0;
        }

        int left = 0;
        for (int i = slen - 1; i >= 1; i--)
            if (s[i] > s[i-1]){
                left = i - 1; break;
            }
        int right = 0;
        for (int i = left; i < slen; i++)
            if (s[i] > s[left]) right = i;

        char c = s[left]; s[left] = s[right]; s[right] = c;
        qsort(s + left + 1, slen - left - 1, sizeof(char), cmp);
        printf("%s\n", s);
    }
    return 0;
}