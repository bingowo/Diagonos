#include<stdio.h>
#include<string.h>
int gcd(int a, int b){
	int t; 
	while(b){
		a=a%b;
		t=a;
		a=b;
		b=t;
	}	
	return a;
}
int main(){
	int n,i;
	scanf("%d\n",&n);
	for(i=0;i<n;i++){
	 	char a[200]; 
		int j=0;
		int sum=0;
		gets(a);
		int l=strlen(a);
		for(j=0;j<l;j++){
	 		unsigned char c=a[j];
	 		while(c!=0){
	 			sum+=c&1;
	 			c>>=1;
			}	
		}	
		int g=gcd(sum,8*j);
		printf("%d/%d\n",sum/g,8*j/g);
	}
	return 0;
}