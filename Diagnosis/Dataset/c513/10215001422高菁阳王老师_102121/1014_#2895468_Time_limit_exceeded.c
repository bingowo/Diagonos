#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void swap(int a[]){
	int i,len,t;
	len=strlen(a);
	for(i=0;i<len/2-1;i++){
		t=a[i];
		a[i]=a[len-i-1];
		a[len-i-1]=t;
	}
}
int main(int argc, char *argv[]) {
	long long m,n,num1,num2,c,a;
	int i,j,s[100],s1[100];char s2[100];
	scanf("%ld %ld",&m,&n);
	num1=m/n;
	num2=m-n*num1;
	for(i=0;num1>0;i++){
		s[i]=num1%3;
		num1=num1/3;}
	swap(s);
  c=i+1;
  i+=2;
	for(;n=1;i++){
		s[i]=(3*num2)/n;
		n=n/3;}
	for(j=i;j>=0;j--){
		s1[j]=s[j]+1;
		if(s1[j]==3)
		s1[j-1]=1;
	}
	for(int k=0;k<=i;k++){
	a=s1[k]-1;
	if(a==-1)
	s2[k]='2';
	if(k==c)
	s2[k]='.';
	s2[k]=a+'0';
}	
	printf("%s",s2);
	
	
		
	
	
	return 0;
}