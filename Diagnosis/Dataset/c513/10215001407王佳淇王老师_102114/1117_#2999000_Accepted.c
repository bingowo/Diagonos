#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
typedef struct{
	long long int x;
	long long int y;
	long long int dis;
}PO;
PO p[1000000];
long long abss(long long x){
	if(x>=0) return x;
	else return -x;
}
long long max(long long a,long long b){
	if(a>=b) return a;
	else return b;
}
int cmp(const void*a,const void*b){
	long long int ax=((PO*)a)->x;
	long long int bx=((PO*)b)->x;
	long long int ay=((PO*)a)->y;
	long long int by=((PO*)b)->y;
	long long int ad=((PO*)a)->dis;
	long long int bd=((PO*)b)->dis;
	if(ad!=bd) return (ad>bd)?1:-1;
	else {
		if(ax!=bx) return (ax>bx)?1:-1;
		else {
			if(ay!=by) return (ay>by)?1:-1;
			else return 0;
		} 	
	}	
}
int main(){
	PO p0;
	scanf("%lld %lld",&p0.x,&p0.y);
	int n;
	scanf("%d",&n);
	for(int v=0;v<n;v++){
	scanf("%lld %lld",&p[v].x,&p[v].y);	
		p[v].dis=max(abss(p[v].x-p0.x),abss(p[v].y-p0.y));
	}
	qsort(p,n,sizeof(PO),cmp);
	long long mdis=p[0].dis;
	printf("%lld\n",mdis);
	printf("%lld %lld\n",p[0].x,p[0].y); 
	/*int cnt=1;
	while(p[cnt].dis==mdis) cnt++;
	printf("%d\n",mdis);
	printf 
	for(int i=0;i<cnt;i++) printf("%lld %lld\n",p[i].x,p[i].y);*/
		return 0;
}