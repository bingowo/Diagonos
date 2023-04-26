#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int a, b;
    for (int i = 0; i != n && scanf("%d %d", &a, &b); i++){
        int cnt = 0, flag = 1;
        for (int j = 0; j != 32; j++){
            if ((flag & a) != (flag & b)) cnt++;
            flag <<= 1;
        }
        printf("%d\n", cnt);
    }
    return 0;
}