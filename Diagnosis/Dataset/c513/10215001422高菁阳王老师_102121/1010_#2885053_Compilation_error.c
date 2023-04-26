#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]) {
	int i,m,n,j,m1
	int s[500];
	
	scanf("%s",s);
	c=strlen(s);
	for(i=0;i<c/3-1;i+=3){
		m=s[i+2]+10*s[i+1]+100*s[i];
		char a[10]={0};
		for(j=10;j>=0;j--){
		a[j]=m%2;
		m=m/2;	
		}printf("%s",a);
	}if(c%3==0){
		m1=s[c-1]+10*s[c-2]+100*s[c-3];
		char a1[10]={0}；
		for(j1=10;j>=0;j--){
		a1[j]=m1%2;
		m1=m1/2;}
		printf("%s",a1);
		}
		for
