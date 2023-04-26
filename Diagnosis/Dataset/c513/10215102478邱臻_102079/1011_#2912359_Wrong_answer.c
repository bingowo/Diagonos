#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
    long long int x,a=0,b=0,i=0,j,qr,qi,r,k;
    int c;
    unsigned int flag=0x8;
    char input[100000];
    scanf("%s",input); //输入-1+i进制数(十六进制表示)
    char bin[100000];
    for(i=0;i<strlen(input);i++){
    	if(input[i]>='A')c=input[i]-'A'+10;
    	else c=input[i]-'0';
    	while(flag){
    		if(c&flag)bin[k++]='1';
    		else bin[k++]='0';
    		flag=flag>>1;
		}
	} //x计入二进制字符串 
	qr=0;qi=0;
	for(j=0;j<k;j++){
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