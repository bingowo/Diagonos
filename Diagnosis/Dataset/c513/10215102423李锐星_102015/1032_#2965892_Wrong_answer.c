#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int n;
	int num[50];
}DATA;

int cmp(const void* a,const void* b)
{
	DATA x,y;
	x=*(DATA*)a;
	y=*(DATA*)b;
	int i;
	for (i=0;x.num[i]!=-1&&y.num[i]!=-1;i++){
		if(x.num[i]>y.num[i]){
			return -1;
		}
		else if(x.num[i]<y.num[i]){
			return 1;
		}
	} 
	if(x.num[i]==-1){
		return 1;
	}
	return -1;
}

int main()
{
	int T;
	scanf("%d",&T);
	int i,j;
	for (i=0;i<T;i++){
		int N;
		DATA data[1001];
		scanf("%d",&N);
		for (j=1;j<=N;j++){
			int number;
			int k=0;
			data[j].n=j;
			scanf("%d",&number);
			while(number!=-1){
				data[j].num[k]=number;
				k++;
				scanf("%d",&number);
			}
			data[j].num[k]=-1;
		}
		qsort(data+1,N,sizeof(data[1]),cmp);
		for(j=1;j<=N;j++){
			int k;
			for (k=0;data[j].num[k]!=-1;k++){
				printf("%d ",data[j].num[k]);
			}
			printf("\n");
		}
	}
	return 0;
}