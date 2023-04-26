#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char s[100];
	int num[100];
	long long int a,b,qr,qi,r,x=0,z=0,n,m,flag,i;
	scanf("%s",s);
	if(strcmp(s,"0x0")==0)printf("0");
	else{
	z=0;
	for(i=2;i<strlen(s);i++){
		if(isalpha(s[i]))x=s[i]-'A'+10;
		else x=s[i]-'0';
		flag=0x8;
		while(flag){
			if(x & flag)num[z++]=1;
			else num[z++]=0;
			flag=flag>>1;
		}
	}
	qr=0;qi=0;r=0;
	for(i=z-1;i>=0;i--){
		r=num[i];
		a=r-qi-qr;b=qr-qi;
		qr=a;qi=b;
	}
	if(a==0){
		if(b==0)printf("0");
		else if(b==1)printf("i");
		else if(b==-1)printf("-i");
		else printf("%lldi",b);
	}
	else if(b==0)printf("%lld",a);
	else {
		if(b>0){
			if(b==1)printf("%lld+i",a);
			else printf("%lld+%lldi",a,b);
		}
		else {
			if(b==-1)printf("%lld-i",a);
			else printf("%lld%lldi",a,b);
		}
	}}
	return 0;
}