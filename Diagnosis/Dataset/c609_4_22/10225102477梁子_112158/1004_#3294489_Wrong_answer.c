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
	while(sum/n!=0){
		ss[j]=a[sum%n];
		sum=sum/n;
		j++;
	}
	ss[j]=a[n];
	for(;j>=0;j--)
	printf("%c",s[j]);
    return 0;
}