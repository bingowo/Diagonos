#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 1000
int main()
{
	int i=0;
	int t;
	scanf("%d",&t);
	for(;i<t;i++){
		char s[N];
		int sum=0;
		int j=0;
		scanf("%s",&s);
		int len=strlen(s);
		int num[N];
		for(;j<len;j++){
			if(s[j]=='-') {
				num[j]=-1;
				sum=sum+num[j]*pow(3,len-1-j);
			}
			else if(s[j]=='0'){
				num[j]=0;
				sum=sum+num[j]*pow(3,len-1-j);
			}
			else if(s[j]=='1'){
				num[j]=1;
				sum=sum+num[j]*pow(3,len-1-j);
			}
	      }
		printf("case #%d:\n",i);
		printf("%d\n",sum);
	}
	return 0;
 } 
