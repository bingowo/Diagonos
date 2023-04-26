#include<stdio.h>

int main(){
    int table[128];
    table['0'] = 0; table['1'] = 1; table['-'] = -1;
    int n;
    scanf("%d", &n);
    char c;
    c = getchar();
    for (int i = 0; i != n; i++){
        int sum = 0;
        while ((c = getchar()) != '\n')
            sum = sum * 3 + table[c];
        printf("case #%d:\n%d\n", i, sum);
    }
    return 0;
}