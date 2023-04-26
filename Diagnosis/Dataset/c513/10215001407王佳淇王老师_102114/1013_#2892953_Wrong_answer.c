#include<stdio.h>
#include<string.h>
long long GCD(long long m,long long n){
	if(n<=m&&n==0) return m;
	else if(m<n) return GCD(n,m);
	else return GCD(n,m%n);
}
int main(){
	char s[100];
	scanf("%s",s);
	unsigned int p;
	long long ansl=0,ansr=0,ans=1,ansr1;
	//存整数 
	for(p=0;p<strlen(s);p++){
		if(s[p]=='.') break;
		ansl=ansl*3;
		if(s[p]=='1') ansl++;
		if(s[p]=='2') ansl--;
	}
	p++;
	//存小数 
	for(;p<strlen(s);p++)
	{
		ansr=ansr*3;
		if(s[p]=='1') ansr++;
		if(s[p]=='2') ansr--;
		ans*=3;
	}
	if(ansl>0&&ansr<0) {
		ansl--;
		ansr=ans+ansr;
	}
	if(ansl<0&&ansr>0){
		ansl++;
		ansr=ans-ansr;
	}
	if(ansl==0&&ansr<0) ansr1=-ansr;

	long long g=GCD(ansr1,ans);
	if(ansr==0) printf("%lld\n",ansl);
	else{
		if(ansl!=0) printf("%lld ",ansl);
		if(ansr<0) printf("-");
		printf("%lld %lld\n",ansr1/g,ans/g);
	}

	return 0;
}