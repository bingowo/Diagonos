#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cnt(char x)
{	int cnt=0;
    while(x!=0){
    	if (x%2)cnt++;
		x/=2;
	}
    return cnt;
}
int GCD(int a,int b){
	int u,v;
	u=a;v=b;
	while(v!=0){
		int tmp1=u%v;
		u=v;
		v=tmp1;
	}
	return u;
}
int main(){
	int n;
	scanf("%d",&n);
	while(n){
		char str[150]={'\0'};
		char *string=str;
		gets(string);
		int cnt1=0;
		int denom=strlen(str)*8*sizeof(char);
		for(int i=0;i<strlen(str);i++){
			cnt1=cnt1+cnt(str[i]);
		}
		int gcd=GCD(cnt1,denom);
		printf("%d/%d\n",cnt1/gcd,denom/gcd);
		n--;
	}
	return 0;
} 