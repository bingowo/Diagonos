#include<stdio.h>
#include<stdlib.h>

int cmp(const void*a,const void*b){
	return *(int*)a-*(int *)b;
}

int main()
{
	int m,n;
	int a[1001],b[1001];
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	scanf("%d",&a[i]);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d",&b[i]);
	int c[1001];
	int cnt=0;
	for(int i=0;i<m;i++){
		int idx=0;
		for(int j=0;j<n;j++){
			if(a[i]==b[j]){
				idx++;
				b[j]=-1;
			}		
		}
		if(idx!=0){
			for(int j=cnt;j<cnt+idx;j++)
			c[j]=a[i];
			cnt+=idx;
		}
	}
	qsort(b,n,sizeof(b[0]),cmp);
	int cas=-1;
	for(int i=0;i<n;i++){
		if(b[i]==-1)
		cas=i;
	}
	for(int i=0;i<cnt;i++)
	printf("%d ",c[i]);
	if(cas==-1){
		for(int i=0;i<n;i++)
		printf("%d ",b[i]);
	}else{
		for(int i=cas+1;i<n;i++)
		printf("%d ",b[i]);
	}
	printf("\n");
	return 0;
}