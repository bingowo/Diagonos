#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void*a,const void*b){
	int *a1=(int*)a;
	int *b1=(int*)b;
	while(*a1!=-1&&*b1!=-1&&*a1==*b1) {
		*a1++;
		*b1++;
	}
	return *b1-*a1;
}
int main(){
	 int d[1000][100];
	int T,N;
	int k;
	scanf("%d\n",&T);
	for(int i=0;i<T;i++){
		scanf("%d\n",&N);
		for(int j=0;j<N;j++)
	{     k=0;
	while(scanf("%d ",&d[j][k])&&d[j][k]!=-1) k++;
	}
	qsort(d,N,sizeof(d[0]),cmp);
	int v,l;	
	for(v=0;v<N;v++)
        {
            for(l=0;d[v][l+1]!=-1;l++)
                   printf("%d ",d[v][l]);
            printf("%d\n",d[v][l]);

        }
	}
	return 0;
}