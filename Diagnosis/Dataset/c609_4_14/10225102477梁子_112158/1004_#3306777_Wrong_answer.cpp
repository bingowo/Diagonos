#include<stdio.h>
#include<string.h>
#define N 32
int main()
{
	int m,n;
	char s[N];
	scanf("%d",&m);
	int sum=0;
	scanf("%s",s);
	int i=strlen(s)-1;
	for(;i>=0;i--){
		if(s[i]>='A'&&s[i]<='Z'){
			sum=sum*m+(s[i]-'A'+10);
		} 
		else if(s[i]>='a'&&s[i]<='z'){
			sum=sum*m+(s[i]-'a'+10);
		}
		else sum=sum*m+(s[i]-'0');
	}
	scanf("%d",&n);
	char a[]="013456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ss[N];
	int j=0;
	for(;sum/n!=0;j++){
		ss[j]=a[sum%m];
		sum=sum/n;
	}
    ss[j]=a[sum];
	for(;j>=0;j--)
		printf("%c",ss[j]);
	
	return 0;
	
 } 
