#include<stdio.h>
#include<math.h>
#include<string.h> 
int main()
{
	int a,b,t[32];
	char s[32];
	scanf("%d%s%d",&a,&s,&b);
	int i,l,n=0;
	l=strlen(s);
	if(s[0]=='0')printf("%d",n);
	else{
	for(i=0;i<l;i++){
		if(s[i]>64&&s[i]<91){
			n+=(s[i]-55)*pow(a,l-1-i);
		}
		else if(s[i]>96&&s[i]<123){
			n+=(s[i]-87)*pow(a,l-1-i);
		}
		else n+=(s[i]-48)*pow(a,l-1-i);
	}
	for(i=0;n!=0;i++){
		t[i]=n%b;
		n/=b;
	}
	for(int j=0;j<i;j++){
		if(t[i-1-j]<10)printf("%d",t[i-1-j]);
		else printf("%c",t[i-1-j]+55);
	}
}}