#include<stdio.h>
int fun(int n, int p, int m, int t){
    if(p==t && m==0)return 1;
    if(m==0 && p!=t || p > n || p < 1)return 0;
    return fun(n, p-1, m-1, t) + fun(n, p+1, m-1, t);
}
int main(){
    int cas;
    scanf("%d",&cas);
    for(cas; cas > 0; cas--){
        int n, p, m, t;
        scanf("%d %d %d %d",&n,&p,&m,&t);
        printf("%d\n",fun(n, p, m, t)); 
    }
}