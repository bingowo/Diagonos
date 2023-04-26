#include <stdio.h>
#include <string.h>

long long pow(long long a,long long b){
	long long c=1;
	for(long long i=0;i<b;i++) c*=a;
	return c;
}

long long GCD(long long a,long long b){
	return b==0?a:GCD(b,a%b);
}

int main(){
	long long A=0,B=0,C=0;
	char num[50];
	scanf("%s",num);
	int len=strlen(num);
	int i=0;
	while(num[i]!='.'){
		i++;
		if(i==len){
			i=len;
			break;
		}
	}
	for(int j=0;j<i;j++){
		if(num[j]=='2') A=A*3-1;
		else A=A*3+(num[j]-'0');
	}
	int k=i+1;
	C=pow(3,len-i-1);
	for (int j=0;j<len-i-1;j++){
		if(num[k+j]=='2') B=B*3-1;
		else B=(num[k+j]-'0')+B*3;
	}
	while((B<0)&&(A>0)){
		A-=1;
		B=C+B;
	}
	if(A<0&&B!=0){
		A+=1;
		B=C-B;
	}
	long long n=GCD(B,C)<0?-GCD(B,C):GCD(B,C);
	if(n%C==0){
		A+=B/n;
		B=0;
	}
	printf("%lld %lld %lld %d %d\n",A,B,C,len,i);
	if(A==0&&B==0) printf("%d",0);
	else if(B==0) printf("%lld",A);
	else if(A==0) printf("%lld %lld",B/n,C/n);
	else printf("%lld %lld %lld",A,B/n,C/n);
	return 0;
}