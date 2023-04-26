#include<stdio.h>
#include<math.h>
//cmp输出1代表 
long long x0,y0;
typedef struct{
	long long a;
	long long b;
}pair;
long long lla(long long a,long long b){
	if(a>=b) return a-b;
	else return b-a;
}
long long pd(long long a,long long b){
	if(a>=b) return a;
	else return b;
}
int cmp(const void*a,const void*b){
	pair x,y;
	x=*(pair*)a;
	y=*(pair*)b;
	if(pd(lla(x.a,x0),lla(x.b,y0))>pd(lla(y.a,x0),lla(y.b,y0))) return 1;
	else if(pd(lla(x.a,x0),lla(x.b,y0))<pd(lla(y.a,x0),lla(y.b,y0))) return -1;
	else{
		if(x.a>y.a) return 1; 
		else if(x.a<y.a) return -1;
		else{
			if(x.b>y.b) return 1;
			else return -1;
		} 
	}
}
int main(){
	int chance;
	scanf("%lld %lld %d",&x0,&y0,&chance);
	int i;
	pair t[chance];
	for(i=0;i<chance;i++){
		scanf("%lld %lld",&t[i].a,&t[i].b);
	}
	qsort(t,chance,sizeof(t[0]),cmp);
	printf("%lld\n",pd(lla(t[0].a,x0),lla(t[0].b,y0)));
	printf("%lld %lld",t[0].a,t[0].b);
}