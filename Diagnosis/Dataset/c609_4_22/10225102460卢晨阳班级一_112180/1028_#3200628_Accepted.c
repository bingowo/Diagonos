#include<stdio.h>
#include<stdlib.h>
typedef struct line{
	int num;
	int a[51];
}ln;

int cmp(const void*p,const void*q){
	ln*pp=(ln*)p;
	ln*qq=(ln*)q;
	int idx=0;
	while(pp->a[idx]!=-1&&qq->a[idx]!=-1){
		if(pp->a[idx]!=qq->a[idx])
			return ((qq->a[idx])-(pp->a[idx]));
		else
			idx++;
	}
	if(pp->a[idx]==-1)
		return 1;
	else
		return -1;
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int n;
		scanf("%d",&n);
		ln b[n];
		for(int j=0;j<n;j++){
			int cnt=0;
			while(scanf("%d",&b[j].a[cnt])!=-1&&b[j].a[cnt]!=-1)
			cnt++;
			b[j].num=cnt;
		}//读入数据 
		qsort(b,n,sizeof(b[0]),cmp);
		for(int j=0;j<n;j++){
			for(int k=0;k<b[j].num;k++)
			printf("%d ",b[j].a[k]);
			printf("\n");
		}//输出数据 
	}
	return 0;
}