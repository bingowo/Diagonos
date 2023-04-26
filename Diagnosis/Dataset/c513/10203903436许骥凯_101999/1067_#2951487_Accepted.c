#include<stdio.h>

int main(){
    int n; scanf("%d", &n);
    long long int res[74] = {0,1,1}; int len = 3;
    for (int i = 0; i != n; i++){
        int t; scanf("%d", &t);
        if (t < len) printf("case #%d:\n%lld\n", i, res[t]);
        else{
            for (; len <= t; len++)
                res[len] = res[len - 1] + res[len - 2] + res[len - 3];
            printf("case #%d:\n%lld\n", i, res[t]);
        }
    }
    return 0;
}