#include <stdio.h>
#include <string.h>
#define N 1000000007

int main()
{
	char s[1001];
	int a[1000];
	scanf("%s",s);
	int i;
	for (i=0;i<strlen(s);i++){
		if(i==0){
			if(strlen(s)==1) a[i]=1;
			else if(s[i]==s[i+1]) a[i]=1;
			else a[i]=2;
		}
		else if(i==strlen(s)-1){
			if(s[i]==s[i-1]) a[i]=1;
			else a[i]=2;
		}
		else {
			if(s[i]==s[i-1]&&s[i]==s[i+1]) a[i]=1;
			else if(s[i]==s[i-1])a[i]=2;
			else if(s[i]==s[i+1])a[i]=2;
			else if(s[i-1]==s[i+1])a[i]=2;
			else{
				a[i]=3;
			}
		}
	}
	unsigned long long res=1;
	for (i=0;i<strlen(s);i++)
	{
		if(res>N){
			res%=N;
		}
		res*=a[i];
	}
	printf("%d\n",res%N);
}