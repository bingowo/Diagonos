#include<stdio.h>
#include<stdlib.h>
int cmp(void *a, void *b){
    int n = *(int *)a, m = *(int *)b, x = 0, y = 0;
    for(int i = 0; i < 64; i++){
        n&1 ==1? x++:0;
        m&1 ==1? y++:0;
        n>>1;
        m>>1;
    }
    if(x > y)return 1;
    if(x < y)return 0;
    if(x == y){
       return(*a > *b? 1:0);
    }
}
int main(){
    int T, k = 0;
    scanf("%d",&T);
    for(T;T > 0;T--){
        int N, a[10000], i = 0, n;
        scanf("%d",&N);
        for(int j = 0;N > j;j++){
            scanf("%d", &n);
            a[i++] = n;
            getchar();
        }
        qsort(a, N, sizeof(int),cmp);
        printf("case #%d\n",k++);
        for(int m  = 0;m < N;m++){
            printf("%d ",a[m]);
        printf("\n");
        }

    }
}
