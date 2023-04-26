#include<stdio.h>
#include<stdlib.h>
int cmp(const void* p1,const void* p2){
	int* a = (int *)p1;
	int* b = (int *)p2;
	int i=1;
	while(*(a+i)==*(b+i)){		
		i++;
	}
	return b[i]-a[i];
}
int main()
{
	int T,N;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		scanf("%d",&N);
		int num[N][51];
		for(int j=0;j<N;j++){
			int a=1;
			while(1){
				scanf("%d",&num[j][a]);
				if(num[j][a]==-1){
					num[j][0] = a;
					break;
				}a++;				
			}
		}
		qsort(num,N,sizeof(int)*51,cmp);
		for(int j=0;j<N;j++){
			for(int k=1;k<num[j][0];k++){
				printf("%d ",num[j][k]);
			}
			printf("\n");
		}
	}
	return 0; 
}
 

