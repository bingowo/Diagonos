#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int n,r,t,x,z,i,j,sign;
	char result[100];
	char R[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	scanf("%d",&t);
	for(i=0;i<t;i++){
		for(j=0;j<100;j++)result[j]='0';
		scanf("%d%d",&n,&r);
		if(n<0){n=-n;sign=-1;}
		else sign=1;  //判断正负 
		if(n==0)printf("0\n");
		else {
			z=0;
			while(n!=0){
				x=n%r;n=n/r;
				result[z++]=R[x];
			}
			if(sign==-1)printf("-");
			for(j=z-1;j>=0;j--)printf("%c",result[j]);
			printf("\n");
		}
	}
	return 0;
}