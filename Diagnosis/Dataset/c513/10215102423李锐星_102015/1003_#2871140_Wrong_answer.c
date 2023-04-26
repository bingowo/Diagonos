#include <stdio.h>
#include <stdlib.h>
long long list[10000];

int cmp(const void *a,const void *b);
int number(long long x);

int main()
{
	int T,i,N,j;
	scanf("%d",&T);
	for(i=0;i<T;i++){
		scanf("%d",&N);
		for (j=0;j<N;j++){
			scanf("%lld",&list[j]);
		}
		printf("case #%d:\n",i);
		qsort(list,N,sizeof(long long),cmp);
		for (j=0;j<N-1;j++){
			printf("%lld ",list[j]);
		}
		printf("%lld\n",list[j]);
	}
	return 0;
}

int cmp(const void *a,const void *b)
{
	long long x,y;
	x=*(long long*)a;
	y=*(long long*)b;
	if (number(y)<number(x)){
		return -1;
	}
	else if (number(y)>number(x)){
		return 1;
		
	}
	else{
		if(x>y){
			return 1;
		}
		else{
			return -1;
		}
	}
}

int number(long long x)
{
	int cnt=0,i;
	if(x<0){
		int num[64];
		for (i=0;i<64;i++){
			num[i]=0;
		}
		x=-x;
		for (i=0;i<64;i++){
			num[i]=x%2;
			x=x/2;
		}
		for(i=0;i<64;i++){
			if (num[i]==1){
				num[i]=0;
			}
			else{
				num[i]=1;
			}
		}
		for (i=0;i<63;i++){
			if (num[i]==0){
				num[i]+=1;
				break;
			}
			else if (num[i]==1){
				num[i]=0;
				num[i+1]+=1;
			}
			else{
				num[i]=1;
				num[i+1]+=1;
			}
		}
		for (i=0;i<64;i++){
			if (num[i]==1){
				cnt++;
			}
		} 
	}
	else{
		for (i=0;x>0;i++){
		if (x%2==1){
			cnt++;
		}
		x=x/2;
		}	
	}
	return cnt;
}