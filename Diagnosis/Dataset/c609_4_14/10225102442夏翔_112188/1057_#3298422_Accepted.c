//1057 高精度*低精度
#include <stdio.h>
#include <string.h>
#define MAXH 100001
int ans[MAXH], len1;
int max(int a, int b){
    return (a>b)? a: b;
}
void multiply(int x){
    int tmp=0, pos=0;
    while(pos<len1){
        ans[pos] = ans[pos]*x+tmp;
        tmp = ans[pos]/10;
        ans[pos++] %= 10;
    }
    while(tmp!=0){
        ans[len1++] = tmp%10;
        tmp /= 10;
    }
}

int main(){
    int T, n, count;
    scanf("%d", &T);
    for(int t=0; t<T; t++){
        scanf("%d", &n);
        memset(ans, 0, sizeof(ans));
        len1 = 1; count = 0;
        ans[0] = 1;
        for(int i=2; i<=n; i++){
            multiply(i); //ret * i
        }
        while(ans[count]==0) count++;
        /*for(int i=0; i<len1; i++) printf("%d", ans[i]);
        printf("\n");*/
        printf("case #%d:\n", t);
        printf("%d\n", count);
    }
    return 0;
}