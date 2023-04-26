#include<stdio.h>
#include<string.h>
#define N 27
int main()
{
	int T;
	scanf("%d",&T);
	for(int k=0;k<T;k++){
		printf("case #%d:\n",k);
		int n1[N]={0},n2[N]={0};
		int prime[N] = {2,3,5,7,11,13,17,
			19,23,29,31,37,41,43,47,53,59
			,61,67,71,73,79,83,89,97,101,103};
		int idx = N-1,len1=0,len2=0;
		int s1[N]={0},s2[N]={0};
		char c;
		while(1){	
			scanf("%d",&s1[len1]);
			len1++;
			c = getchar();
			if(c==' '||c=='\n')
				break;
		}
		while(1){	
			scanf("%d",&s2[len2]);	
			len2++;
			c = getchar();
			if(c=='\n')
				break;
		}
		for(int j=len1-1,p=N-1;j>=0;j--,p--){
			n1[p] = s1[j];
		}
		for(int j=len2-1,p=N-1;j>=0;j--,p--){
			n2[p] = s2[j];
		}
		int a=0;
		int ret[N] = {0},r=0;
		for(idx = N-1;idx>=N-len1||idx>=N-len2;idx--){			
			ret[idx] = n1[idx]+n2[idx]+r;
			r = 0;
			while(ret[idx]>=prime[a]){
				ret[idx] -= prime[a];
				r ++;
			}
			a++;
		}
		ret[idx] = r;
		idx = 0;
		while(ret[idx]==0)
			idx++;
		for(;idx<N-1;idx++){
			printf("%d,",ret[idx]);
		}
		printf("%d\n",ret[N-1]);
	}
	return 0;
} 