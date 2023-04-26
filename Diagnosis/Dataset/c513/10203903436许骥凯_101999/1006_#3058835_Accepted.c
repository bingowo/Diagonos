#include<stdio.h>

int main(){
    int T; scanf("%d", &T); getchar();  //去除输入T后输入的换行符
    int table[128]; table['-'] = -1; table['0'] = 0; table['1'] = 1;
    for (int i = 0; i != T; ++i){
        printf("case #%d:\n", i);
        char c;   
        int res = 0;
        while((c = getchar()) != '\n')
            res = res * 3 + table[c];
        printf("%d\n", res);
    }
    return 0;
}