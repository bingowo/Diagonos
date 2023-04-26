#include<stdio.h>
int run(int n,int p,int m,int t){
    if(m==0){
        if(p!=t)return 0;
        else return 1;
    }
    if(p==1)return run(n,p+1,m-1,t);
    else if(p==n)return run(n,p-1,m-1,t);
    else{
        return run(n,p-1,m-1,t)+run(n,p+1,m-1,t);
    }
}
int main(){
    int cas;
    scanf("%d",&cas);
    for(int i=0;i<cas;i++){
        int n,p,m,t,sum;
        scanf("%d%d%d%d",&n,&p,&m,&t);
        sum=run(n,p,m,t);
        printf("%d\n",sum);
    }
    return 0;
}