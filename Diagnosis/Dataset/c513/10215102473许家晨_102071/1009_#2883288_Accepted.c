#include<stdio.h>
#include<string.h>
int GCD(int a,int b){
	int u,v;
	u=a;v=b;
	while(v!=0){
		int tmp1=u%v;
		u=v;
		v=tmp1;
	}
	return u;
}
int main(){
	int n;
	scanf("%d",&n);
	unsigned char str[150]={'\0'};
	getchar();
	while(n){
		gets(str);
		
		int len=strlen(str);
		int cnt1=0;
		int denom=len*8*sizeof(char);
		for(int i=0;i<strlen(str);i++){
			int c=(unsigned char)str[i];
			while(c!=0){
				if(c%2)cnt1++;
				c/=2;
			}
		}
		int gcd=GCD(cnt1,denom);
		printf("%d/%d\n",cnt1/gcd,denom/gcd);
		n--;
	}
	return 0;
} 