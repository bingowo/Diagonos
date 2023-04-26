#include<stdio.h>
#include<string.h>
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int cnt=0;
		char s[121];
		scanf("%*c%[^\n]",s);
		int len=strlen(s);
		int sum=0;
		for(int j=0;j<len;j++){
			for(int p=0;p<8;p++){
				sum=sum+s[j]%2;
				s[j]=s[j]>>1;
			}
		}
		int q=gcd(sum,8*len);
		//printf("here:%d\n",len);
		printf("%d/%d\n",sum/q,8*len/q);
	}
	return 0;
}