#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int trans(char *x,char *y){
	int k=0;
	for(int i=2;i<strlen(x);i++){
		int d;
		if(x[i]>='A')d=x[i]-'A'+10;
		else d=x[i]-'0';
		unsigned int flag=0x8;
		while(flag){
			if(d&flag) y[k++]='1';
			else y[k++]='0';
			flag=flag>>1;
		}
	}
	return k;
} //十六进制转化二进制 
int main(){
	char x[18];
	scanf("%s",x);
	char y[65]={'\0'};
	int k=trans(x,y);
	
	long long qr=0,qi=0;
	long long a,b;
	for (int i=0;i<k;i++){
		int r=y[i]-'0';
		a=-qr-qi+r;
		b=qr-qi;
		qr=a;qi=b;
	}
	if(qi==0){
		printf("%lld\n",qr);
	}
	else{
		if(qr!=0){
			printf("%lld",qr);
			if(qi>0)printf("+");
		}
		if(qi==1)printf("i\n");
		else if (qi==-1)printf("-i\n");
		else {printf("%lld",qi);printf("i\n");
		
		}
	}
	return 0;
}