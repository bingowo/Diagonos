#include <stdio.h>
#include <stdlib.h>

typedef struct{
	unsigned long long r;
	unsigned long long h;
	unsigned long long s;
}CYLINDER;

int cmp(const void* a,const void* b)
{
	CYLINDER x,y;
	x=*(CYLINDER*)a;
	y=*(CYLINDER*)b;
	if(x.s>y.s){
		return -1;
	}
	return 1;
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	CYLINDER a[1001];
	int i;
	for (i=0;i<n;i++){
		scanf("%llu %llu",&a[i].r,&a[i].h);
		a[i].s=a[i].r*a[i].h*2;
	}
	unsigned long long res=0,ans=0;
	for (i=0;i<n;i++){
		res=0;
		CYLINDER b[1000];
		int k=0,j;
		for (j=0;j<n;j++){
			if(j!=i&&a[j].r<=a[i].r){
				b[k]=a[j];
				k++;
			}
		}
		qsort(b,k,sizeof(CYLINDER),cmp);
		if(k!=0&&k>=m-1){
			for (j=0;j<m-1;j++){
				res+=b[j].s;
			}
		}
		res+=a[i].r*a[i].r+a[i].s;
		if(res>ans){
			ans=res;
		}
	}
	printf("%llu\n",ans);
	return 0;
}