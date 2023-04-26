#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	char s[1000],t[1000];
	int number=0,i,k,j;
	unsigned int flag;
	long long int qi=0,qr=0,a,b,r;
	scanf("%s",s);  //输入复数进制的数字（16进制）
	if(s[2]=='0')printf("0");
	else {
		k=0;
		for(i=2;i<strlen(s);i++){
			if(s[i]>='A')number=s[i]-'A'+10;
			else number=s[i]-'0';
			flag=0x8;
			while(flag){
				if(number & flag)t[k++]='1';
				else t[k++]='0';
				flag=flag>>1;
			}
		}
	for(j=0;j<k;j++){
		r=t[j]-'0';
		a=-qr-qi+r;b=qr-qi;
		qr=a;qi=b;
	}  //计算复数
	if(a==0){  //没有实部 
	    if(b==1)printf("i\n");
	    else if(b==-1)printf("-i\n");
		else printf("%lldi\n",b); 
	} 
	else if(b==0){
		printf("%lld\n",a);
	}
	else if(a!=0 && b!=0){
		if(b>0){
			if(b==1)printf("%lld+i",a);
			else printf("%lld+%lldi",a,b);
		}
		else if(b<0){
			if(b==-1)printf("%lld-i",a);
			else printf("%lld%lldi",a,b);
		}
	}}
	return 0;
}