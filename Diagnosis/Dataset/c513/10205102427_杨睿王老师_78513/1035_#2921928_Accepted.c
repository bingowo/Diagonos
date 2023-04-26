//1035
/*
算法：上面的面积会被虽然会被遮盖住，但会被新的圆柱体的上面再补上，所以理论上可视的表面积为，
最下面的圆柱的所有面积-底面积+上面所有圆柱的侧面 
*/
#include<stdio.h>
#include <stdlib.h>
typedef unsigned long long ll;
typedef struct v{
	ll r;
	ll h;
	ll totalsurface;
	ll sidesurface;
}V;
int cmp(const void * a, const void * b){
	V aa=*(V*)a;
	V bb=*(V*)b;
	if(aa.sidesurface>bb.sidesurface) return -1;
	else return 1;
}
int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	int i=0;
	V n[1010];
	for(int r=0;r<1010;r++){
		n[r].h=0;
		n[r].r=0;
		n[r].sidesurface=0;
		n[r].totalsurface=0;
	}
	for(i=0;i<N;i++){
		scanf("%lld %lld",&n[i].r,&n[i].h);
		n[i].sidesurface=2*n[i].r*n[i].h;
		ll temp=n[i].r*n[i].r;
		n[i].totalsurface=n[i].sidesurface+temp;
	}
	qsort(n,N,sizeof(V),cmp);
	ll ans=0;
	for(int i=0;i<N;i++){
		ll sum=n[i].totalsurface;
		ll cnt=1;
		for(int j=0;j<N && cnt<M;j++){
			if(i==j || n[j].r>n[i].r) continue;
			sum+=n[j].sidesurface;
			cnt++;
		}
		if(cnt==M){
			if(sum>ans) ans=sum;
		}
	}

	printf("%lld",ans);
	
}