#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int num[50];
}DATA;
int cmp(const void *a,const void *b)
{
	DATA x,y;
	x=*(DATA*)a;
	y=*(DATA*)b;
	int i;
	for(i=0;x.num[i]!=-1&&y.num[i]!=-1;i++){
		if(x.num[i]>y.num[i]){
			return -1;
		}
		if(x.num[i]<y.num[i]){
			return 1;
		}
	}
	if(x.num[i]==-1){
		return 1;
	}
	return -1;
}
void solve(int T)
{
	int N;
	scanf("%d",&N);
	DATA data[1000];
	int i,j;
	for (i=0;i<N;i++){
		for (j=0;j<100;j++){
			scanf("%d",&data[i].num[j]);
			if(data[i].num[j]==-1){
				break;
			}
		}
	}
	qsort(data,N,sizeof(data[0]),cmp);
	for (i=0;i<N;i++){
		for (j=0;data[i].num[j]!=-1;j++){
			printf("%d ",data[i].num[j]);
		}
		printf("\n");
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	int i;
	for (i=0;i<T;i++){
		solve(i);
	}
	return 0;
}