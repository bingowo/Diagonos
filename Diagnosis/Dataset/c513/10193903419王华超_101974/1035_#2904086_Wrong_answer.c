#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000
typedef struct{
	int h,r;
	long long ds,hs;
}column;
int cmp(const void*p1,const void*p2){
	column a=*((column*)p1),b=*((column*)p2);
	if(a.hs>b.hs){
		return 1;
	}
	else{
		return -1;
	}
}
int main()
{
   	int i,n,m;
   	scanf("%d %d",&n,&m);
   	column l[N];
   	for(i=0;i<n;i++){
   		scanf("%d %d",&l[i].r,&l[i].h);
   		l[i].ds=l[i].r*l[i].r;
   		l[i].hs=l[i].r*2*l[i].h;
	}
	qsort(l,n,sizeof(l[0]),cmp);
	long long  s=0;
	for(i=0;i<m;i++){
		s+=l[i].hs;
	}
	long long max=s+l[0].ds;
	for(i=1;i<m;i++){
		if(s+l[i].ds>max){
			max=s+l[i].ds;
		}	
	}
	for(i=m;i<n;i++){
		s=s-l[m-1].hs;
		if(s+l[i].ds+l[i].hs>max){
			max=s+l[i].ds+l[i].hs;
		}
	}
	printf("%lld",max);
	return 0;
}