#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int max(int a,int b){
	if(a>b) return a;
	else return b;
}
int f(int x,int y){
   	int i,j,num=0;
	   for(i=0,j=0;max(x,y)>0;){
	   i=x%2;
	   j=y%2;
	   x=x/2;
	   y=y/2;
	   if(i!=j) num++;}
	   
	   
}return num;

int main(int argc, char *argv[]) {
	int i,m,n;
	scanf("%d\n",&i);
	for(;i>0;i--){
		scanf("%d %d",&m,&n);
		printf("%d\n",f(m,n));
	}
	
	
	return 0;
}