#include<stdio.h>
#include<string.h>
#define N 100
int main()
{
	int m,n;
	char s[N];
	scanf("%d",&m);
	int i=0;
	int sum=0;
	while(scanf("%c",&s[i])!=EOF){
		i++;
	}
	for(;i>=0;i--){
		if(s[i]>=48&&s[i]<=57){
			sum=sum*m+(s[i]-48);
		} 
		else if(s[i]>=65&&s[i]<=90){
			sum=sum*m+(s[i]-55);
		}
		else sum=sum*m+(s[i]-87);
	}
	scanf("%d",&n);
	char a[]="013456789ABCDEF"
	char ss[N];
	int j=0;
	for(;sum/n!=0;j++){
		ss[j]=a[sum%m];
		sum=sum/n;
	}
	for(;j>=0;j--){
		printf("%c",s[j]);
	
	return 0;
	
 } 