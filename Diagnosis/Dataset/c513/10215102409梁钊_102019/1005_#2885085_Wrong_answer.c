#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int T = 0 ;
	scanf("%d",&T) ;
	for(int i = 0 ; i < T ; i++){
		char s[50] = {'0'} ;
		scanf("%s",&s) ;
		double sum = 0 ;
		for(int j = strlen(s)-1 ; j > 1 ; j--){
			sum = (sum+(int)(s[j]-'0')) / 8.0 ;
		}
		printf("%lf",sum);
	}
}