#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int num;
	int pos;
}B;

int cmp(const void *a,const void *b)
{
	B x,y;
	x=*(B*)a;
	y=*(B*)b;
	if(x.pos==-1&&y.pos==-1)return x.num-y.num;
	else if(x.pos==-1&&y.pos!=-1) return 1;
	else if(x.pos!=-1&&y.pos==-1) return -1;
	return x.pos-y.pos;
}

int main()
{
	int a[1000];
	int m;
	scanf("%d",&m);
	for (int i=0;i<m;i++){
		scanf("%d",&a[i]);
	}
	int n;
	scanf("%d",&n);
	B b[500];
	for (int i=0;i<500;i++){
		b[i].pos=-1;
	}
	for (int i=0;i<n;i++){
		scanf("%d",&b[i].num);
		for (int j=0;j<m;j++){
			if(a[j]==b[i].num){
				b[i].pos=j;
				break;
			}
		}
	}
	qsort(b,n,sizeof(b[0]),cmp);
	for (int i=0;i<n;i++){
		printf("%d ",b[i].num);
	}
	printf("\n");
	return 0;
}