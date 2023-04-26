#include<stdio.h>
#include<math.h>

int func(int n, int m){
    if (n<m) return 0;
    else if (n==m) return 1;
    else return 2*func(n-1, m)+pow(2, n-m-1)-func(n-m-1, m);
}


int main(){
    int n=0, m=0;
    while (scanf("%d %d", &n, &m)!=EOF&&(n!=-1&&m!=-1)){
        int res = func(n, m);
        printf("%d\n", res);
    }
    return 0;
}