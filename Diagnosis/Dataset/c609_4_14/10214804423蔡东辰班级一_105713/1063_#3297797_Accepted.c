#include <stdio.h>
int main(){
    long long a[51] = {1, 1, 2, 4, 8};//f(0),f(1),f(2),f(3),f(4)
    for(int i = 5; i<51; i++){
        a[i] = a[i-4] + a[i-3] + a[i-2] + a[i-1];
    }
    int T; scanf("%d", &T);
    for(int i = 0; i<T; i++){
        int n; scanf("%d", &n);
        printf("case #%d:\n%lld\n", i, a[n]);
    }
    return 0;
}
