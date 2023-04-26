#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
	char s[1000];
	scanf("%s",s);
	char*p=s;
	char x[1000]={'\0'};
	int j=0;
	p=p+2;
	while(*p){ x[j++]=*p;
	p++;
	}
	// 十六进制转二进制，把每位十六进制数用对应的四位二进制数来代替
	char er[1000]; 
	int k=0,i;
	for(i=0;i<strlen(x);i++){
		int d=0;
		unsigned int flag=8;//二进制为1000 
		if(x[i]>'A') d=x[i]+10-'A';
		else d=x[i]-'0';
		while(flag){
		if(d&flag) er[k++] ='1';
		else er[k++]='0';
		flag=flag>>1;
	}
	}//********
	 int qr=0,qi=0,r=0,l,qrr,qii;//a+bi=(qr+q1i)*(-1+i)+r得到a=-qr-qi+r,b=qr-qi 
	 for(l=0;l<k;l++){
	 	r=er[l]-'0';//取值时一定注意是否为字符数组 
	 	qrr=-qr-qi+r;
	 	qii=qr-qi;
	 	qr=qrr,qi=qii;
	 }
		if(qr!=0) printf("%d",qr);
		if(qr!=0&&qi>0) printf("+");
		if(qi==1) printf("i");
		else if(qi>0&&qi!=1) printf("%di",qi);
		else if(qi==-1) printf("-i");
		else if(qi<0&&qi!=-1) printf("%di",qi); 
		else if(qr==0&&qi==0) printf("0");
	return 0;
}
