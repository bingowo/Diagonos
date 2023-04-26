#include <stdio.h>

int GCD(int a,int b){
	return b==0?a:GCD(b,a%b);
}
int main(){
	int T=0;
	scanf("%d",&T);
	char a[120];
	for (int i=0;i<T;i++){
		int j=0;
		while (scanf("%c",&a[j++])!=EOF) ;
		char *p=a;
		int x=0,y=0;
		while(*p++){
			char m=*p;
			while(m){
				if (m%2==1) x++;
				m/=2;
			}
			y+=8;
		}
		int n=GCD(x,y);
		printf("%d/%d\n",x/n,y/n); 
	}
	return 0;
}