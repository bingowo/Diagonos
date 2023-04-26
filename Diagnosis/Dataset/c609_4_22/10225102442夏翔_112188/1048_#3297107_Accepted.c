//1048 高精度加高精度
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int len;
void *add(int *x1, int *x2, int *sum){
    int pos=0, temp=0;
    while(pos<len){ //高精度+高精度
        sum[pos] += x1[pos]+x2[pos]+temp;
        temp = sum[pos]/10;
        sum[pos++] %= 10;
    }
    while(temp!=0){
        sum[len++] = temp%10;
        temp /= 10;
    }
}
int main(){ //不可用递归，否则tl
    int T, n;
    int **ans;
    scanf("%d", &T);
    for(int t=0; t<T; t++){
        scanf("%d", &n);
        printf("case #%d:\n", t);
        if(n<=2){
            printf("%d\n", n>=1);
            continue;
        }
        len = 1;
        ans = (int**)malloc(sizeof(int*)*(n+1));
        for(int i=0; i<=n; i++)
            ans[i] = (int*)calloc(100, sizeof(int));
        ans[1][0] = 1; ans[2][0] = 1;
        for(int i=3; i<=n; i++){
            add(ans[i-2], ans[i-1], ans[i]);
        }
        for(int i=0; i<len; i++) printf("%d", ans[n][len-i-1]);
        printf("\n");
    }
    return 0;
}