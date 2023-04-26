#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int sum=0;
void plan(int n,int p,int m,int t){
    if(m==0&&p==t)sum=sum+1;
    else if(m==0&&p!=t)return;
    else if(m!=0&&p!=t){
        if(p==1)plan(n,p+1,m-1,t);
        else if(p==n)plan(n,p-1,m-1,t);
        else{
            plan(n,p+1,m-1,t);
            plan(n,p-1,m-1,t);
        }
    }
    else return;
}
int main(){
    int cos;
    scanf("%d",&cos);
    for(int coss=0;coss<cos;coss++){
        int n,p,m,t;
        scanf("%d%d%d%d",&n,&p,&m,&t);
        plan(n,p,m,t);
        printf("%d\n",sum);
    }
    return 0;
}