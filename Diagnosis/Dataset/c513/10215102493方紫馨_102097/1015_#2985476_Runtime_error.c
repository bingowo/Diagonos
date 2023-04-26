#include<stdio.h>
#include<string.h>
#define N 27
int main()
{
	int T;
	scanf("%d",&T);
	for(int k=0;k<T;k++){
		printf("case #%d:\n",k);
		char s1[N],s2[N];
		scanf("%s%s",s1,s2);
		int n1[N]={0},n2[N]={0};
		int prime[N] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53
			,59,61,67,71,73,79,83,89,97,101,103};
		int idx = N-1,len1=0,len2=0;
		for(int i=strlen(s1)-1;i>=0;i-=2){
			n1[idx--] = s1[i] - '0';
			len1++;
		}
		idx = N -1;
		for(int i=strlen(s2)-1;i>=0;i-=2){
			n2[idx--] = s2[i] - '0';
			len2++;
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