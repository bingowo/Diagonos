//1068  dfs
#include <stdio.h>
int num;
void dfs(int n, int p1, int m1, int t){
    if(m1==0){
        if(p1==t)
            num++;
        return;
    } 
    if(p1==1) dfs(n, p1+1, m1-1, t);
    else if(p1==n) dfs(n, p1-1, m1-1, t);
    else{
        dfs(n, p1+1, m1-1, t);
        dfs(n, p1-1, m1-1, t);
    }
}
int main(){
    int T, n, p, m, t;
    scanf("%d", &T);
    for(int k=0; k<T; k++){
        scanf("%d %d %d %d", &n, &p, &m, &t);
        num = 0;
        dfs(n, p, m, t);
        printf("%d\n", num);
    }
    return 0;
}