//1035
/*
算法：上面的面积会被虽然会被遮盖住，但会被新的圆柱体的上面再补上，所以理论上可视的表面积为，
最下面的圆柱的所有面积+上面所有圆柱的侧面 
*/
#include<stdio.h>
#include <stdlib.h>
typedef long long ll;
typedef struct v{
	int r;
	int h;
	ll totalsurface;
	ll topsurface;
	ll sidesurface;
}V;
int cmp(const void * a, const void * b){
	V aa=*(V*)a;
	V bb=*(V*)b;
	return bb.totalsurface-aa.totalsurface;
}
int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	int i=0;
	V n[1010];
	for(i=0;i<N;i++){
		scanf("%d %d",&n[i].r,&n[i].h);
		n[i].sidesurface=2*n[i].r*n[i].h;
		n[i].topsurface=n[i].r*n[i].r;
		n[i].totalsurface=n[i].sidesurface+n[i].topsurface;
	}
	qsort(n,N,sizeof(V),cmp);
	ll ans=n[0].totalsurface;
	for(int i=1;i<M;i++){
		ans+=n[i].sidesurface;
	}
	printf("%lld",ans);
	
}