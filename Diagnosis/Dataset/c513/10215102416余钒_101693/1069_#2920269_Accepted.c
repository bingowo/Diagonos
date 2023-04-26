#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int T;
long long x;
int check(int x){
	int num[20],top=0;
	while(x) num[++top]=x%10,x/=10;
	for(int i=1;i<=top/2;i++) if(num[i]!=num[top-i+1]) return 0;
	return 1;
}
int main() {
	scanf("%lld",&x);
	int cnt=0;
	while(!check(x)){
		cnt++;
		long long num=0,tmp=x;
		while(tmp) num=num*10+tmp%10,tmp/=10;
		x+=num;
	}
	printf("%d %lld\n",cnt,x);
	return 0;
}
