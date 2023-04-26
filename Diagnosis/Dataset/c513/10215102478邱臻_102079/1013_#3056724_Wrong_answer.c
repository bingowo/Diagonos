#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
long long int gcd(long long int a,long long int b){
	long long n,m;
	n=a>b?a:b;m=(a>=b)?b:a;
	if(n%m!=0){
		a=m;m=n%m;n=a;
	}
	return m;
}
int main(int argc, char *argv[]) {
	char s[31];
	long long int a=0,b=0,c=0,x,i,j,n,m;
	scanf("%s",s);
	//只有整数部分
	if(strchr(s,'.')==NULL){
		for(i=0;i<strlen(s);i++){
			if(s[i]=='2')a=a*3-1;
			else a=a*3+s[i]-'0';
		}
		printf("%lld",a);
	} 
	//只有小数部分 
	else if(s[0]=='0'){
		for(i=strlen(s)-1;i>=2;i--){
			if(s[i]=='2')x=-1;
			else x=s[i]-'0';
			if(c==0){  //分母为0 
				c=x*3;b=1;
			}
			else {
				x=x*c;b=b+x;
				c=c*3;
				n=b;
				if(c<0){
					m=-c;
					b=n/gcd(n,m);c=-m/gcd(n,m);
				}
				else {
					m=c;
					b=n/gcd(n,m);c=m/gcd(n,m);
				}
			}  //通分进行计算 
		}
		if(c<0){c=-c;b=-b;}
		printf("%lld %lld",b,c);
	}
	//既有整数也有小数
	else {
		i=0;
		while(s[i]!='.'){
			if(s[i]=='2')a=a*3-1;
			else a=a*3+s[i]-'0';
			i++;
		}  //整数部分计算
		for(j=strlen(s)-1;j>i;j--){
			if(s[j]=='2')x=-1;
			else x=s[j]-'0';
			if(c==0){  //分母为0 
				c=x*3;b=1;
			}
			else {
				x=x*c;b=b+x;
				c=c*3;
				n=b;
				if(c<0){
					m=-c;
					b=n/gcd(n,m);c=-m/gcd(n,m);
				}
				else {
					m=c;
					b=n/gcd(n,m);c=m/gcd(n,m);
				}
		    }
		}  //小数部分计算 
		if(a<0 && c>0){
			b=c-b;
			if(a==-1)printf("%lld %lld",b,c);
			else {
			    a+=1;
			    printf("%lld %lld %lld",a,b,c);	
			}		
		} 
		else if(a>0 && c<0){
			b=-c-b;
			if(a==1)printf("%lld %lld",b,-c);
			else {
			    a-=1;
			    printf("%lld %lld %lld",a,b,-c);
			}
		}
		else {
			if(c<0)printf("%lld %lld %lld",a,b,-c);
			else printf("%lld %lld %lld",a,b,c);
		}
	} 
	return 0;
}