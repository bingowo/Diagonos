#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
    long long int x,a=0,b=0,c,i=0,j,qr,qi,r,len;
    scanf("%llx",&x); //输入-1+i进制数(十六进制表示)
    char bin[100];
    while(x!=0){
    	c=x%2;x=x/2;
    	bin[i]=c+'0';
    	i++;
	}
	bin[i]='\0'; //x计入二进制字符串 
	len=strlen(bin);
	qr=0;qi=0;
	for(j=len-1;j>=0;j--){
		r=bin[j]-'0';
		a=-qr-qi+r;
		b=qr-qi;
		qr=a;qi=b;
	}
	if(qi==0){
		printf("%lld\n",qr);
	}
	else {
		if(qr!=0){
			printf("%lld",qr);
			if(qi>0)printf("+");
		}
		if(qi==1)printf("i\n");
		else if(qi==-1)printf("-i\n");
		else{
			printf("%lldi\n",qi);
		}
	}
	
	return 0;
}