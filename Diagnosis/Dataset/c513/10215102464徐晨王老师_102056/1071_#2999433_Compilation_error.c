#include <stdio.h>
#include <stdlib.h>
#define p 10007
//（a*b）%p==a%p*b%p
//C(m,n) %p= C(m/p,n/p)*C(m%p,n%p)%p
//p为素数

unsigned long long int mod(int x,int y){
    unsigned long long int ret=1;
    for(int i=0;i<y;i++){
        //乘取余再取余。
        ret=ret*(x%p);
        ret=ret%p;
    }
    return ret;
}

unsigned long long int Cmn(int k, int n)
{
	if(n>k){
		return 0;
	}
	if(n>k-n){
		n=k-n;
	}
	unsigned long long int ret=1;
	unsigned long long int ny;
	for(int i=1;i<=n;i++){
		ret=ret*((k+1-i)%p);
		//除法无法同余，计算逆元，用到了费马小定理计算。 
		ny=mod(i,p-2);
		ret=(inverse*ret)%p;
	}
	
	
	return ret;
}

unsigned long long int Lucas(int x,int y){
    return Cmn(x%p,y%p)*Cmn(x/p,y/p);//x，y比较小，无需递推。
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int a,b,k,n,m;
        scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
        printf("case #%d:\n",t);
        printf("%llu\n",mod(a,n)*mod(b,m)*Lucas(k,n)%p);
    }
}