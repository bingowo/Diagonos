#include<stdio.h>
#include<string.h>
int GCD(int a,int b){
	if(b==0) return a;
	else return GCD(b,a%b);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int k=0;k<n;k++){
		char s[130];
		int a,count=0,x=0;
		scanf("%s",s);
		printf("%s",s);
		int len=strlen(s);
		for(int i=0;i<len;i++){
			a=s[i];
			while(a){
				a=a&(a-1);
				count++;
			}
			a=s[i];
			while(a){
				a=a/2;
				x++;
			}
		}
		int gcd;
		gcd=GCD(count,x);
		printf("%d/%d\n",count/gcd,x/gcd);
	}
	return 0;
} 