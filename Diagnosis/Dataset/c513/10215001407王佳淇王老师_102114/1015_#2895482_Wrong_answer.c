#include<stdio.h>
#include<string.h>
#include<ctype.h>
void read(char*s,int*x){
	int l=strlen(s);
	int c=0;
	for(int j=0;j<l;j++){
		if(isdigit(s[j])) 
		{
		x[c]=s[j]-'0';
		c++;
		} 
	}
}
void ADD(int a[],int b[],int c[]){
	int prime[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
	int*p=&a[sizeof(a)/sizeof(a[0])];
	int*q=&b[sizeof(b)/sizeof(b[0])];
	int*k=&prime[26];
	int num=0;
	for(;(p>&a[0])||(q>&b[0]);p--,q--,k--){
		if((*p+*q)>=*k) {
		c[num]=(*p+*q)%(*k);
		c[num+1]+=(*p+*q)/(*k);}
		else c[num]=*p+*q;
	}
}
void output(int c[]){
	int ll=sizeof(c)/sizeof(c[0]);
	for(;ll>=0;ll--){
		printf("%d",c[ll-1]);
		if(ll>0) printf(",");
	}
	printf("\n");
	
}
int main(){
	int T;
	scanf("%d",&T);
	int A[26]={0},B[26]={0},C[26]={0};
	char s[100];
	for(int i=0;i<T;i++)
	{
	scanf("%s",s); read(s,A);
	scanf("%s",s); read(s,B);
	ADD(A,B,C);
	printf("case #%d:\n",i);
	output(C);
}
return 0;
}