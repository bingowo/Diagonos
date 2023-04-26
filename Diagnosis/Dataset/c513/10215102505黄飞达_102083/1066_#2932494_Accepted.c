#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int n, p, m, t;
int res = 0;

int abs(int a){
    return a < 0 ? -a : a;
}

int dfs(int f, int time){
    if (time >= m){
        if (f==t) return 1;
        else return 0;
    }
    if (f+1<=n) res += dfs(f+1, time+1);
    if (f-1>=1) res += dfs(f-1, time+1);
    return 0;
}

int main(){
    int cas=0;
    scanf("%d ", &cas);
    for (int i=0; i<cas; i++){
        scanf("%d %d %d %d", &n, &p,  &m, &t);
        res = 0;
        if (m < abs(p-t) || (m-abs(p-t))%2!=0) {printf("0\n"); continue;}
        dfs(p, 0);
        printf("%d\n", res);
    }
    return 0;
}