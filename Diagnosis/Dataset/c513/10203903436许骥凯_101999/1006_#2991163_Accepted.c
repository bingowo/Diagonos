#include<stdio.h>
#include<string.h>

int main(){
    int T; scanf("%d", &T);
    int table[128]; table['1'] = 1; table['0'] = 0; table['-'] = -1;
    for (int i = 0; i != T; i++){
        printf("case #%d:\n", i);
        char s[100]; scanf("%s", s);
        int res = 0;
        for (int i = 0; i != strlen(s); i++)
            res = table[s[i]] + 3 * res;
        printf("%d\n", res);
    }
    return 0;
}