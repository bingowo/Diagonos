#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int gcd(int n,int m);
int main(){
	int n;
	int a = 0,b = 0;
	int divisor = 1;
	char temp;
	scanf("%d",&n);
	scanf("%c",&temp);         //提前读入\n 
	char s[120];
	int j = 0;
	char c1;
	for(int i = 0;i < n;i++){
		while((c1 = getchar()) != '\n' && c1 != EOF){
			if(0x4e00 <= c1 && c1 <= 0x9fbb){
				s[j] = c1;
				s[j++] = getchar();
			}else
				s[j++] = c1;
		}
		s[j] = '\0';
		b = 8 * strlen(s);
		for(int k = 0;s[k] != '\0';k++){
			for(int r = 0;r < 8;r++){
				if(s[k] & 1)	
					a++;
				s[k] >>= 1;
			}
		}
		divisor = gcd(a,b);
		a /= divisor;
		b /= divisor;
		printf("%d/%d\n",a,b);
		a = 0;
		b = 0;
		j = 0;
		memset(s,0,sizeof(s));
	}
	return 0;
}
int gcd(int m,int n){
	if(n == 0)
		return m;
	return gcd(n,m % n);
}