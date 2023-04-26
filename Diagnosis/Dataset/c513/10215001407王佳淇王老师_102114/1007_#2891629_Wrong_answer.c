#include<stdio.h>
#include<math.h>
#include<string.h>
void trans(unsigned long long n,char*s){
	int j=0;
	while(n){
		s[j]=n%2-'0';
		n/=2;
		j++;
	}s[j]='\0';
	
}
int main()
{
	int T;
	unsigned long long N;
	char s[50];
	scanf("%d\n",&T);
	for(int i=0;i<T;i++){
		scanf("%d",&N);
		printf("case #%d:\n",i);
		trans(N,s);
		int ans=0,count=0;
		for(int k=0;k<strlen(s);k++){
		if(s[k]=='1') count++;
		else {ans=fmax(ans,count);	
		count =0; 	}
	}ans=fmax(ans,count);
	printf("%d\n",ans);
	}
	return 0;}