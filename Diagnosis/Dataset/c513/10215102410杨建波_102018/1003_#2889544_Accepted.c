#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b){
    int  x = 0, y = 0;
    long long int n = *(long long int *)a, m = *(long long int *)b;
    for(int i = 0; i < 64; i++){
        if((n>>i&1)==1) x++;
        if((m>>i&1)==1) y++;
    }
    if(x > y)return -1;
    else if(x < y)return 1;
    else{
       if(n >= m)return 1;
       else return -1;
    }
}
int main(){
    int T, k = 0;
    scanf("%d",&T);
    for(T;T > 0;T--){
        int N,i = 0;
        long long int n,a[10000];
        scanf("%d",&N);
        for(int j = 0;N > j;j++){
            scanf("%lld", &n);
            a[i++] = n;
            getchar();
        }
        qsort(a, N, sizeof(long long int), cmp);
        printf("case #%d:\n",k++);
        for(int m  = 0;m < N;m++){
            printf("%lld ",a[m]);
        }
printf("\n");
    }
}
