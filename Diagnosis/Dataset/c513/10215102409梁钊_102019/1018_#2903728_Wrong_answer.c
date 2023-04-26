#include<stdio.h>

int main()
{
	int Primenum[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	long long r[25]; long long tmp ;
	for(int i=0;i!=25;i++){
		r[i] = tmp ;
		tmp = tmp * Primenum[i] ;
	}
	int n[25] ; int i=0;
	while(scanf("%d",&n[i++]) != EOF && getchar() != '\n') ;
	long long result = 0 ; int j = 0 ;
	for(i--;i!=-1;i--){
		result = result + r[j++] * n[i] ;
	}
	printf("%lld",result) ;
}