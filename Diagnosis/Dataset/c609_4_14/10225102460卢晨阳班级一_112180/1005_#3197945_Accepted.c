#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		char a[20];
		scanf("%s",a);
		int m=1;
		int sum=0;
		for(int j=strlen(a)-1;j>=0;j--){
			if(a[j]=='-'){
				sum=sum-m;
				m=m*3;
			}
			else if(a[j]=='0')
				m=m*3;
			else if(a[j]=='1'){
				sum=sum+m;
				m=m*3;
			}
		}
		printf("case #%d:\n%d\n",i,sum);
	}
	return 0;
 } 