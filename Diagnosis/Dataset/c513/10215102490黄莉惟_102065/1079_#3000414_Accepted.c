#include <stdio.h>
#include <stdlib.h>
#include<stdio.h>
#include<malloc.h>
int cmp(const void *a, const void *b){
    int t;long long pa = *(long long *)a, pb = *(long long *)b;
    return pa > pb ? 1: -1;
}
int main(){
    int n, m, cas, L, U;
    long long ans = 0;
    scanf("%d", &cas);
    for(int j = 0; j < cas; j++){
        scanf("%d %d",&n,&m);
        long long* a = (long long*)malloc(sizeof(long long) * n*(n+1)/2);
        for(int i = 0; i < n; i++){
            scanf("%lld",&a[i]);
        }
        
        for(int i = 1; i < n; i++){
            int index = i*n - i*(i-1)/2;
            for(int k = 0; index < (i+1)*n - (i+1)*i/2; index++, k++){
                a[index] = a[k] + a[index - n + i];//printf("%lld ", a[index]);
            }
        }
        qsort(a, n*(n+1)/2, sizeof(long long), cmp);
        /*for(int k = 0; k < n*(n+1)/2; k++){
            printf("%lld", a[k]);
        }*/
        printf("case #%d:\n", j);
        for(int k = 0; k < m; k++){
            scanf("%d%d",&L,&U);
            if(L == U) ans = a[L-1];
            else{
                for(int i = L - 1; i <= U - 1; i++){
                    ans += a[i];//printf("%lld\n", a[i]);
                }
            }
            
            printf("%lld\n", ans);
            ans = 0;
        }
        
        
        //system("pause");
    }
    
    return 0;
}