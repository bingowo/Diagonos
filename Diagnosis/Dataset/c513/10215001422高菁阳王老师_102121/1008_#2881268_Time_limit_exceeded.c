#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int max(int a,int b){
	if(a>b) return a;
	else return b;
}
int f(int x,int y){
   	int i,j,num=0,k=0,q=0;
	   char a1[100]={0};
	   char a2[100]={0};
	    for(j=0;x>0;j++){
	a1[j]=x%2;
	x=x/2;}
	for(j=0;y>0;j++){
	a2[j]=x%2;
	x=x/2;}
   	  while(a1[k]) k++;
	 while(a2[q]) q++;
	   for(i=0;i<=max(k,q);i++){
	   	if(a1[i]==a2[i]) num++;
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