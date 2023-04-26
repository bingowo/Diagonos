#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LL unsigned long long
int T,n; 
LL gcd(LL a,LL b){
	if(a<b){
		LL tmp=a;
		a=b,b=tmp;
	}
	if(a%b==0) return b;
	else return gcd(b,a%b);
}
LL pow(LL a,int b){
	LL ans=1;
	for(int i=1;i<=b;i++) ans*=a;
	return ans;
}
char s[1005];
int main() {
	scanf("%d",&T);
	for(int c=0;c<T;c++){
		scanf("%s",s);
		LL a=0,b=0,pos=0,ls=0;
		for(int i=0;s[i];i++){
			if(s[i]=='.') pos=i;
			else if(s[i]=='['){
				pos=i-pos-1;
				for(int j=i+1;s[j+1];j++) b=b*10+s[j]-'0',ls++;
				break;
			}else
				a=a*10+s[i]-'0';
		}
		if(b==0){
			LL p=pow(10,strlen(s)-pos-1);
			if(a==0) printf("case #%d:\n0\n",c);
			else printf("case #%d:\n%llu/%llu\n",c,a/gcd(a,p),p/gcd(a,p));
		}else{
			LL p=pow(10,pos),rs=pow(10,ls)-1,B=p*rs,A=b+a*rs;
			printf("case #%d:\n%llu/%llu\n",c,A/gcd(A,B),B/gcd(A,B));
		}
	}
	return 0;
}