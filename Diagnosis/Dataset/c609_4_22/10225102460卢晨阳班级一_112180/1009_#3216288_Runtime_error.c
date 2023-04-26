#include<stdio.h>

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int cnt=0;
		char s[121];
		while(scanf("%c",&s[cnt])!=-1&&s[cnt]!='\n')
			cnt++;
		int sum=0;
		for(int j=0;j<cnt;j++){
			for(int p=0;p<8;p++){
				sum=sum+s[j]%2;
				s[j]=s[j]>>1;
			}
		}
		int q=gcd(sum,8*cnt);
		printf("%d/%d\n",sum/q,8*cnt/q);
	}
	return 0;
}