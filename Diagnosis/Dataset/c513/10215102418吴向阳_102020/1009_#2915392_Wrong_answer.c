#include <stdio.h>

int GCD(int a,int b){
	return b==0?a:GCD(b,a%b);
}

int main(){
	int T=0;
	scanf("%d",&T);
	char a[241];
	getchar();
	for (int i=0;i<T;i++){
		gets(a);
		char *p=a;
		int x=0,y=0;
		while(*p){
			char m=*p;
			if(m<0){
				x++;
				m=-m;
			}
			while(m){
				if(m%2==1) x++;
				m/=2;
			}
			y+=8;
			*p++;
		}
		int n=GCD(x,y);
		printf("%d/%d\n",x/n,y/n); 
	}
	return 0;
}