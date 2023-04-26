#include<stdio.h>
#include<string.h>
int gcd(int a,int b){
	return a%b==0?b:gcd(b,a%b);
}
int main(){
	int t;
	scanf("%d",&t);getchar();
	while(t--){
		int ret=0;
		int sumbite=0;
		char ch;
		while((ch=getchar())!='\n'){
			sumbite++;
			char temp=ch;
			for(int j=0;j<8;j++){
				if(temp&1)ret++;
				temp>>=1;
			}
		}
		int sumbit=sumbite*8;
		int d=gcd(ret,sumbit);
		ret/=d,sumbit/=d;
		printf("%d/%d\n",ret,sumbit);
	}
}