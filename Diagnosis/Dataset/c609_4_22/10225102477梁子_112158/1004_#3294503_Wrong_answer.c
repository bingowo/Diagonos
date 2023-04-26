#include<stdio.h>
#include<string.h>
#define N 32
int main()
{
    int n,m;
	char s[N];
	int sum=0;
	scanf("%d",&m);
	scanf("%s",s);
	int i=strlen(s)-1;
	for(;i>=0;i--){
		if(s[i]>='a'&&s[i]<'z')
		sum=sum*m+s[i]-'a';
		else if(s[i]>='A'&&s[i]<'Z')
		sum=sum*m+s[i]+s[i]-'A';
		else sum=sum*m+s[i];
	} 
	scanf("%d",&n);
	char *a="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ss[N];
	int j=0;
	for(;sum/n!=0;j++){
		ss[j]=a[sum%n];
		sum=sum/n;
	}
	ss[j]=a[n];
	for(;j>=0;j--)
	printf("%c",ss[j]);
    return 0;
}