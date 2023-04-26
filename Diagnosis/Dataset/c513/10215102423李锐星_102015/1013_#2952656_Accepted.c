#include <stdio.h>
#include <string.h>
#include <math.h>
long long gcd(long long a,long long b)
{
	if(a>b){
		int t;
		t=a;
		a=b;
		b=t;
	}
	if(b%a==0){
		return a;
	}
	else{
		return gcd(a,b%a);
	}
}
int main()
{
	char s[50];
	scanf("%s",s);
	long long  integer=0;
	long long un=1,up=0;
	int i;
	for (i=0;s[i]!='.'&&s[i]!='\0';i++){
		if(s[i]=='1'){
			integer=integer*3+1;
		}
		else if(s[i]=='2'){
			integer=integer*3-1;
		}
		else{
			integer=integer*3;
		}
	}
	if(s[i]=='.'){
		for (i=i+1;i<strlen(s);i++){
		if(s[i]=='1'){
			up=up*3+1;
		}
		else if(s[i]=='2'){
			up=up*3-1;
		}
		else{
			up*=3;
		}
		un*=3;
		}
		long long t=gcd(abs(up),un);
		if(t<0){
			t=-t;
		}
		up/=t;
		un/=t;
	}
	if(integer*up>0){
		if(integer<0){
			integer-=1;
			up=un+up;
		}
		printf("%lld %lld %lld\n",integer,up,un);
	}
	else if(integer*up<0){
		if(integer>0){
			integer-=1;
			up=un+up;
		}
		else{
			integer+=1;
			up=un-up;
		}
		printf("%lld %lld %lld\n",integer,up,un);
	}
	else{
		if(integer==0&&up!=0){
			printf("%lld %lld\n",up,un);
		}
		else if(integer!=0&&up==0){
			printf("%lld\n",integer);
		}
		else{
			printf("0\n");
		}
	}
	
	return 0;
}