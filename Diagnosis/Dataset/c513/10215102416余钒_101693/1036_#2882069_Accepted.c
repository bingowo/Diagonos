#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int T,n,m;
struct node{
	long long x,y;
}A[1005];
int cmp(const void* a,const void* b){
	struct node x=*(struct node*)a,y=*(struct node*)b;
	if(1ull*llabs(x.x)+llabs(x.y)!=1ull*llabs(y.x)+llabs(y.y)){
		if(1ull*llabs(x.x)+llabs(x.y)>1ull*llabs(y.x)+llabs(y.y)) return -1;
		else return 1;
	}
	if(x.x!=y.x){
		if(x.x>y.x) return 1;
		else return -1;
	}
	if(x.y>y.y) return 1;
	else return -1;
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&A[i].x,&A[i].y);
		
	qsort(A+1,n,sizeof(struct node),cmp);
	if(1ull*llabs(A[1].x-A[2].x)+llabs(A[1].y-A[2].y)==0 && 1ull*llabs(A[1].x-A[2].x)!=0) printf("18446744073709551616\n");
	else printf("%llu\n",1ull*llabs(A[1].x-A[2].x)+llabs(A[1].y-A[2].y));
	int cnt=0;
	
	for(int i=2;i<=n;i++){
		unsigned long long dx=1ull*llabs(A[i].x-A[i-1].x)+llabs(A[i].y-A[i-1].y);
		int res=0; 
		while(dx>0){
			if((dx&1) == 0){
				res=-1;
				break;
			}
			res++;
			//printf("%lld\n",dx);
			if((dx&2) || dx==1 ) dx>>=1;
			else dx=(dx>>1)+1;
		}
		if(res==-1) break;
		cnt+=res;
	}
	printf("%d\n",cnt);
	return 0;
}