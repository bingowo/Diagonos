#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
long long int gcd(long long int a,long long int b){
	long long int n,m;
	n=a>b?a:b;m=a>b?b:a;
	if(m==0)return n;
	else return gcd(m,n%m);
}
int main() {
	char s[1000];
	long long int number=0,i,j,location,up=1,down=1;
	scanf("%s",s);
	if(strchr(s,'.')==NULL){
		for(i=0;i<strlen(s);i++){
			if(s[i]=='2')number=number*3-1;
			else number=number*3+s[i]-'0';
		}
		printf("%lld",number);
	}
	else {
		location=strchr(s,'.')-&s[0];
		for(j=0;j<location;j++){
			if(s[j]=='2')number=number*3-1;
			else number=number*3+s[j]-'0';
		}  //计算整数部分
		down=3;
		if(s[location+1]=='2')up=up*(-1);
		else up=up*(s[location+1]-'0');  //第一个小数部分 
		for(j=location+2;j<strlen(s);j++){
			down=down*3;
			if(s[j]=='2')up=up*3-1;
			else up=up*3+s[j]-'0';
		}   //计算小数部分
		if(number>0){
			if(up<0){
				number--;up=down+up;
			}
			printf("%lld %lld %lld",number,up/gcd(up,down),down/gcd(up,down)); 
		}
		else if(number<0){
			if(up>0){
				number++;up=down-up;
			}
			printf("%lld %lld %lld",number,up/gcd(up,down),down/gcd(up,down)); 
		}
		else if(number==0){
			if(up>0)printf("%lld %lld",up/gcd(up,down),down/gcd(up,down));
			else printf("%lld %lld",up/gcd(-up,down),down/gcd(-up,down));
		}
		
	}
	return 0;
}