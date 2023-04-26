#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define p 10007
//（a*b）%p==a%c*b%p
//C(m,n) %p= C(m/p,n/p)*C(m%p,n%p)
//p为素数

int mod(int x,int y){
    int ret=1;
    for(int i=0;i<y;i++){
        ret=ret*(x%p);
        ret=ret%p;
    }
    return ret;
}

int Cmn(int x,int y){
    int sum=1;
    for(int i=1;i<=y;i++){
        sum=sum*(x-y+i)/i;
    }
    return sum;
}

int Lucas(int x,int y){
    return Cmn(x/p,y/p)*Cmn(x%p,y%p);
}

int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int a,b,k,n,m;
        scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
        printf("case #%d:\n",mod(a,n)*mod(b,m)*Lucas(k,n));
        printf("%d\n",)
    }
}