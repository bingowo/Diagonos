#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int max(int a,int b){
	if(a>b) return a;
	else return b;
}
char er(int x){
	int i;
	char s[100];
	for(i=0;x>0;i++){
	s[i]=x%2;
	x=x/2;
		
	}
}
int f(int x,int y){
   	int i,num=0,k=0,q=0;
	   char a1[100]={0};
	   char a2[100]={0};
	    a1[100]=er(x);
       a2[100]=er(y);
   	while(a1[k]) k++;
	 while(a2[q]) q++;
	   for(i=0;i<=max(k,q);i++){
	   	if(a1[i]!=a2[i]) num++;
	   	else continue;
	   }return num;
	   
}

int main(int argc, char *argv[]) {
	int i,m,n;
	scanf("%d\n",&i);
	for(;i>0;i--){
		scanf("%d %d",&m,&n);
		printf("%d\n",f(m,n));
	}
	
	
	return 0;
}