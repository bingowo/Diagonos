#include<stdio.h>
#include<math.h>
long long cal(int x,int y){   //用来算组合数的值
    int i;
    long long sum1=1,sum2=1,sum3=1;
    for(i=1;i<=x;i++){
    	sum1=sum1*i;
	}
	for(i=1;i<=y;i++){
		sum2=sum2*i;
		if(y==0) sum2=1;
	}
	for(i=1;i<=x-y;i++){
		sum3=sum3*i;
	}
	if(x==y) sum3=1;
	return (sum1/sum2)/sum3;
}
int main(){
	int chance;
	scanf("%d",&chance);
	int i;
	for(i=0;i<chance;i++){
		int n,p,m,t;     //n代表总共的楼数，p代表目前所处的楼数，m代表分钟数，t代表最终的楼数 
		scanf("%d%d%d%d",&n,&p,&m,&t);
		if((p-t-m)%2==0){
			long long ret=cal(m,abs(m-p+t)/2);
			if(p-1<abs(m-p+t)/2) ret-=cal(m-p,abs(m-p+t)/2-p);
			if(n-p<abs(m-p+t)/2) ret-=cal(n-p,abs(m-p+t)/2-n+p);
			printf("%lld\n",ret);
		}
		else printf("0");
	}
}