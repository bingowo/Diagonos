#include<stdio.h>
int fun(int n, int p, int m, int t){
    if(p==t && m==0)return 1;
    else if(m==0 && p!=t )return 0;
    else if(p > n || p < 1)return 0;
    else return fun(n, p-1, m-1, t) + fun(n, p+1, m-1, t);
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