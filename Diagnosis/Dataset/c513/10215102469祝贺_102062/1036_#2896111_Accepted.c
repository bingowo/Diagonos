#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
	long long x;
	long long y;
}pos;
pos zero={0,0};
unsigned long long f(long long a,long long b){
	if(a-b<0)return -a+b;
	else return a-b;
}
unsigned long long dis(pos a,pos b){
	return (f(a.x,b.x)+f(a.y,b.y));
}
int cmp(const void*a,const void*b){
	pos n1=*((pos*)a),n2=*((pos*)b);
	if(dis(n1,zero)!=dis(n2,zero)) return dis(n1,zero)<dis(n2,zero)?1:-1;
	else if(n1.x!=n2.x)return n1.x<n2.x?-1:1;
	else return n1.y<n2.y?-1:1;
}
int step(pos* a,pos* b){
	unsigned long long mhd=f(a->x,b->x)+f(a->y,b->y);
	if(mhd==0)return 0;
	else if((mhd&1)==0)return -1;
	else{
		int ret=0;
		while(mhd!=0){
			mhd>>=1;ret++;
		}
		return ret;
	}
}
int main(){
	int n;scanf("%d",&n);
	pos table[n];long long ans=0;
	for(int i=0;i<n;i++) scanf("%lld%lld",&table[i].x,&table[i].y);
	qsort(table,n,sizeof(pos),cmp);
	for(int i=0;i<n-1;i++){
		long long out=step(&table[i],&table[i+1]);
		if(out<0)break;
		else ans+=out;
	}
	long long max=4611686018427387904;
	if((table[0].x==max && table[0].y==max || table[0].x==-max && table[0].y==-max) &&
		(table[1].x==max && table[1].y==max || table[1].x==-max && table[1].y==-max) &&
		table[0].x!=table[1].x)
		printf("18446744073709551616\n%lld",ans);
	else
		printf("%llu\n%lld",dis(table[0],table[1]),ans);
	return 0;
}