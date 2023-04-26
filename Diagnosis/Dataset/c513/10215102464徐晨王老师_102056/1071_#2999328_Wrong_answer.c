#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define p 10007
//（a*b）%p==a%c*b%p
//C(m,n) %p= C(m/p,n/p)*C(m%p,n%p)%p
//p为素数

int mod(int x,int y){
    int ret=1;
    for(int i=0;i<y;i++){
        ret=ret*(x%p);
        ret=ret%p;
    }
    return ret;
}

int Cmn(int k, int n)
{
	if(n > k){
		return 0;
	}
	if(n > k - n){
		n = k - n;
	}
	int ret = 1;
	int inverse;
	for(int i = 1; i <= n ; i ++){
		ret = (ret * (k + 1 - i)) % p;
		//这里计算了逆元，用到了费马小定理计算。 
		inverse = mod(i, p - 2);
		ret = (inverse * ret) % p;
	}
	
	
	return ret;
}

int Lucas(int x,int y){
    return Cmn(x%p,y%p)*Cmn(x/p,y/p)%p;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int a,b,k,n,m;
        scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
        printf("case #%d:\n",t);
        printf("%d\n",mod(a,n)*mod(b,m)*Lucas(k,n));
    }
}