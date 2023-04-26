#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int num;
	int flag;
}B;

int cmp(const void* a,const void* b)
{
	B x,y;
	x=*(B*)a;
	y=*(B*)b;
	if(x.flag==-1&&y.flag==-1){
		if(x.num<y.num){
			return -1;
		}
		else{
			return 1;
		}
	}
	else if(x.flag==-1&&y.flag!=-1){
		return 1;
	}
	else if(x.flag!=-1&&y.flag==-1){
		return -1;
	}
	else{
		return x.flag-y.flag;
	}
}

int main()
{
	int m,n;
	int a[501];
	B b[501];
	int i;
	scanf("%d",&m);
	for (i=0;i<m;i++){
		scanf("%d",&a[i]);
	}
	for (i=0;i<501;i++){
		b[i].flag=-1;
	}
	scanf("%d",&n);
	for (i=0;i<n;i++){
		scanf("%d",&b[i].num);
		for (int j=0;j<m;j++){
			if(a[j]==b[i].num){
				b[i].flag=j;
				break;
			}
		}
	}
	qsort(b,n,sizeof(B),cmp);
	for (i=0;i<n;i++){
		printf("%d ",b[i].num);
	}
	printf("\n");
	return 0;
}