#include <stdio.h>
#include <stdlib.h>
//判断i是否能被w里的数给通过加减表示。
int x[3] = {-1, 0, 1};
int isPossible(int i, int* w, int n){
    //对于w里的所有n个砝码，它可以放右边，可以放左边，可以不放
    int r = 0;
    if(i==0){
        return 1;
    }
    if(n == 0){
        return 0;
    }
    for(int j = 0; j<3; j++){
        r = isPossible(i+x[j]*w[n-1], w, n-1);
        if(r){return 1;}
    }
    return 0;
}
int main(){
    int n;
    scanf("%d", &n);
    int w[n]; int sum = 0;
    for(int i = 0; i<n; i++){
        scanf("%d", &w[i]);
        sum += w[i];
    }
    for(int i = 1; i<sum+1; i++){
        printf("%d", isPossible(i, w, n));
    }
    return 0;
}