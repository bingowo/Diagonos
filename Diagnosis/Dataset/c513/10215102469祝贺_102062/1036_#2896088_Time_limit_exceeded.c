#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
	long long x;
	long long y;
}pos;
pos zero={0,0};
long long f(long long a,long long b){
	if(a-b<0)return -a+b;
	else return a-b;
}
long long dis(pos a,pos b){
	return (f(a.x,b.x)+f(a.y,b.y));
}
int cmp(const void*a,const void*b){
	pos n1=*((pos*)a),n2=*((pos*)b);
	if(dis(n1,zero)<dis(n2,zero)) return 1;
	else return -1;
}
long long step(pos* a,pos* b){
	long long r=f(a->x,b->x),c=f(a->y,b->y);
	if(((r+c)&1)==0)return -1;
	else{
		int ret=0;long long mhd=c+r;
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
	printf("%lld\n%lld",dis(table[0],table[1]),ans);
	return 0;
}