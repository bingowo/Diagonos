#include<stdio.h>

int n,t,s;

void count(int p,int m){
    if(m==0){
        if(p==t)s++;
        return;
    }
    else if(m>0){
        if(p==1)count(2,m--);
        else if(p==n)count(n-1,m--);
        else{
            count(p-1,m--);count(p+1,m--);
        }
    }
}

int main(){
    int cas;
    scanf("%d",&cas);
    while(cas--){
        int p,m;
        scanf("%d %d %d %d",&n,&p,&m,&t);
        s=0;
        count(p,m);
        printf("%d\n",s);
    }
}