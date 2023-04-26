#include<stdio.h>

void count(int n,int p,int m,int t,int s){
    if(m==0){
        if(p==t)s++;
        return;
    }
    else if(m>0){
        if(p==1)count(n,2,m--,t,s);
        else if(p==n)count(n,n-1,m--,t,s);
        else{
            count(n,p-1,m--,t,s);count(n,p+1,m--,t,s);
        }
    }
}

int main(){
    int cas;
    scanf("%d",&cas);
    while(cas--){
        int n,p,m,t,s=0;
        scanf("%d %d %d %d",&n,&p,&m,&t);
        count(n,p,m,t,s);
        printf("%d\n",s);
    }
}