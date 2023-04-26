#include<stdio.h>
#include<ctype.h>
#include<string.h>
void work(int a,int b,int n){
	int a0,b0,a1=a,b1=b;
	for(int i=1;i<n;i++){
		a0=a*a-b*b;
		b0=a*b1+b*a1;
		a1=a0;
		b1=b0;
	}
	printf("%d",a0);
	if(b0>0) printf("+%di",b0);
	else printf("%di",b0);
}
int main(){
	char s[100];
	int n;
	scanf("%s",s);
	scanf("%d",n);
	int len=strlen(s);
	int flag1=1,flag2=1,i=0,real=0,v=0;
	if(s[0]=='-') 
	{
	flag1=-1;
	for(i=1;i<len;i++){
	if(isdigit(s[i])) real=real*10+s[i]-'0';
	else if(s[i]=='+'||s[i]=='-') break;
		}
	/*real=real*flag;*/}
	else for(i=0;i<len;i++){
	if(isdigit(s[i])) real=real*10+s[i]-'0';
	else if(s[i]=='+'||s[i]=='-') break;
		}
	real*=flag1;	
	int j=i;
	if(s[i]=='-') flag2=-1;
	for(j=i+1;j<len;j++){
		if(isdigit(s[j])) v=v*10+s[j]-'0';
		else if(s[j]=='i') break;
	}
	if(s[i+1]=='i') v=1;
	v*=flag2;
	work(real,v,n);
	
}