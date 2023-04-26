#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int gcd(int n,int m);
int main(){
	int n;
	char temp;
	int a = 0,b = 0;
	int divisor = 1;
	scanf("%d",&n);
	scanf("%c",&temp); 
	char s[n][120];
	for(int i = 0;i < n;i++){
		scanf("%[^\n]",s[i]);
		scanf("%c",&temp);
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;s[i][j] != '\0';j++){
			b++;
		}
		b *= 8;
		int k;
		for(k = 0;s[i][k] != '\0';k++){
			if(s[i][k] == ' ' || s[i][k] =='\t')
				continue;
			else{
				while(s[i][k]){
					if(s[i][k] & 1)
						a++;
					s[i][k] >>= 1;
				}
			}
		}
		divisor = gcd(a,b);
		a /= divisor;
		b /= divisor;
		printf("%d/%d\n",a,b);
		a = 0;
		b = 0;
	} 
	return 0;
}
int gcd(int m,int n){
	if(n == 0)
		return m;
	return gcd(n,m % n);
}