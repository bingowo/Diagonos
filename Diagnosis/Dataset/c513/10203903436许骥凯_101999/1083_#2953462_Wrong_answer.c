#include<stdio.h>

int main(){
    int n; scanf("%d", &n);
    for (int i = 0; i != n; i++){
        printf("case #%d:\n", i);
        int t; scanf("%d", &t);
        int cnt = 0;
        for (int i = 1; i <= t; i++)
            if (!(i % 5)) cnt++;
        printf("%d\n", cnt);
    }
    return 0;
}