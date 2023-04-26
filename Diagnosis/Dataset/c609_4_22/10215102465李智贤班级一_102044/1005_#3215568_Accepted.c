#include <stdio.h>
#include <string.h>
int main() {
    int T;
    scanf("%d", &T);
    getchar();
    int hash[256] = {0};
    hash['-']=-1, hash['1']=1,  hash['0']=0;
    for(int i = 0; i < T; ++i) {
        char s[100];
        gets(s);
        int r = 0;
        for(int i = 0, l = strlen(s); i < l; ++i) {
            r = r * 3 + hash[s[i]];
        }
        printf("case #%d:\n%d\n", i, r);
    }
    return 0;
}