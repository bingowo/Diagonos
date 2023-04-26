#include <stdio.h>
char table[16]="0123456789ABCDEF";
int f1(int a,char num[]){
	int i,ret=0;
	for(i=0;num[i];i++){
		if(num[i]>='0'&&num[i]<='9')ret=ret*a+num[i]-'0';
		if(num[i]>='A'&&num[i]<='Z')ret=ret*a+num[i]-'A'+10;
		if(num[i]>='a'&&num[i]<='z')ret=ret*a+num[i]-'a'+10;
	}
	return ret;
} 
void f2(int n,int b){
	if(n/b){
		f2(n/b,b);
	}
	putchar(table[n%b]);
}
int main(){
	int a,b;
	char num[30];
	scanf("%d%s%d",&a,num,&b);
	f2(f1(a,num),b);
}