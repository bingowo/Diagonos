#include<stdio.h>
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
	 	char a[120]; 
		int b=0,j=0;
		int sum=0;
	 	scanf("%s\n",a);
	 	while(a[j]){
	 		while(a[j]){
	 			b=a[j]&1;
	 			a[j]>>=1;
	 			if(b==1)sum++;
			}	j++;
		}	
		int g=gcd(sum,8*j);
		printf("%d/%d\n",sum/g,8*j/g);
	}
	return 0;
}