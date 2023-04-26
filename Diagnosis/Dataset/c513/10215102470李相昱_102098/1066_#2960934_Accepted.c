#include <stdio.h>
int cnt,t,n;
void fun(int p,int m){
    if(m==0){
        if(p==t){
            cnt ++;
        }
        return;
    }
    if(p==1){
        fun(2,m-1);
    }else if(p ==n){
        fun(n-1,m-1);
    }else{
        fun(p+1,m-1);
        fun(p-1,m-1);
    }
}
int main() {
    int cas;
    scanf("%d",&cas);
    while (cas--){
        int p1,m;
        scanf("%d%d%d%d",&n,&p1,&m,&t);
        cnt =0;
        fun(p1,m);
        printf("%d\n",cnt);
    }
    return 0;
}
