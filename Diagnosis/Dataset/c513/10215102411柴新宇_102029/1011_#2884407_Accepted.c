#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	char s[1000],t[1000];
	scanf("%s",s);
	int k=0,d;
	int i; 
	for(i=2;i<strlen(s);i++){
		if(s[i]>='A')d=s[i]-'A'+10;
		else {
			d=s[i]-'0';
		}
		unsigned int flag=0x8;
		while(flag){
			if(d&flag)t[k++]='1';
			else t[k++]='0';
			flag>>=1;
		}
	}
	long long qr=0,qi=0,a,b;
	int j;
	for(j=0;j<k;j++){
		int r=t[j]-'0';
		a=-qr-qi+r;
		b=qr-qi;
		qr=a;
		qi=b;
	}
	if(qi==0){
		printf("%lld\n",qr);
	}
	else {
		if(qr!=0){
			printf("%lld",qr);
			if(qi>0)printf("+");
		}
		if(qi==1){
			printf("i\n");
		}
		else if(qi==-1){
			printf("-i\n");
		}
		else{
			printf("%lld",qi);
			printf("i\n");
		}
	}
	
	return 0;
}