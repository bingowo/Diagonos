#include<stdio.h>

int main(){
    int n; scanf("%d", &n);
    for (int i = 0; i != n; i++){
        printf("case #%d:\n", i);
        int t; scanf("%d", &t);
        int cnt = 0;
        for (int i = 1; i <= t; i++){
            int temp = i;
            while(temp){
                if (!(temp % 5)) cnt++;
                temp /= 5;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}