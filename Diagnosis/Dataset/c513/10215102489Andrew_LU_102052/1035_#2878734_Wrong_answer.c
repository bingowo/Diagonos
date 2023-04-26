#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct{
	int r;
	int h;
	int s;
}p;
int ma(int a, int b){
	return a>b? a:b;
}
int cmp1(const void* x,const void* y){
	return (*(p*)x).s<(*(p*)y).s;
}
int main(){
	int n,m,i;
	p a[1005];
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d%d",&a[i].r,&a[i].h);
		a[i].s=2*a[i].r*a[i].h;
	}
	qsort((void *)a,n,sizeof(a[0]),cmp1);
	int maxr=0;
	long long ans=0;
	for(i=0;i<m-1;i++){
		ans+=a[i].s;
		if(a[i].r>maxr) maxr=a[i].r;
	}
	long long tmp=0;
	for(i=m-1;i<n;i++){
		if(tmp<ma(maxr,a[i].r)*ma(maxr,a[i].r)+a[i].s) tmp=ma(maxr,a[i].r)*ma(maxr,a[i].r)+a[i].s;
		//printf("%d\n",tmp);
	}
	printf("%lld",ans+tmp);
}