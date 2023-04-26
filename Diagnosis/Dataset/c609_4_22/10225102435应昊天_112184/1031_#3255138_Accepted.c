#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void* a,const void* b);
int main(){
	int T;
	scanf("%d",&T);
	int n,m;
	int L,U;
	for(int i = 0;i < T;i++){
		scanf("%d %d",&n,&m);
		int* p = (int*)malloc(sizeof(int) * (n+1));
		for(int j = 0;j < n;j++){
			scanf("%d",&p[j]);
		}
		long long* q = (long long *)malloc(sizeof(long long) * (n*(n+1)/2 + 1));
		int cnt = 0;
		for(int x = 0;x < n;x++){                               
			for(int inc = 0;inc < n;inc++){                       //increment
				q[cnt] = 0;
				if(x + inc >= n)
					break;
				else{
					for(int y = 0;y < inc+1;y++){
						q[cnt] += p[x+y];
					}
					cnt++;
				}
			}
		}
		qsort(q,n*(n+1)/2,sizeof(long long),cmp);
		printf("case #%d:\n",i);
		for(int k = 0;k < m;k++){
			long long  sum = 0;
			scanf("%d %d",&L,&U);
			for(int r = L-1;r < U;r++){
				sum += q[r];
			}
			printf("%lld\n",sum);
		}
		free(p);
		free(q);
	}
} 
int cmp(const void* a,const void* b){
	if(*(int*)a > *(int*)b)
		return 1;
	else
		return -1;
}