#include <stdio.h>
#include <stdlib.h>

int cmp(const void* A,const void* B){
	int *x=(int*)A,*y=(int*)B;
	while(*x==-1&&*y==-1&&*x==*y)x++,y++;
	return *y-*x;
}

int main(){
	int k=0,N;
	scanf("%d",&N);
	for(k=0;k<N;k++){
		int a[1000][51],i,j,n;
		scanf("%d",&n);
		for(i=0;i<n;i++,j=0){
			do{scanf("%d",&a[i][j++]);}
			while(a[i][j-1]!=-1);
		}
		qsort(a,n,sizeof(a[i]),cmp);
		for(i=0;i<n;i++){
			j=0;
			while(a[i][j]!=-1){
				printf(j=0?"":" ");
				printf("%d",a[i][j++]);
			}
			printf("\n");
		}
	}
	return 0;
}