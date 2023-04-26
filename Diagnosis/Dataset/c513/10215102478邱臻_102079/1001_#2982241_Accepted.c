#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	char R[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char result[100];
	int t,r,i,n,a,j,sign=1,k;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		for(j=0;j<100;j++)result[j]='\0';
		scanf("%d%d",&n,&r);  //数字和进制
		if(n<0){
			n=-n;sign=-1;
		}
		else sign=1;
		j=0;
		while(n!=0){
			a=n%r;n=n/r;
			result[j++]=R[a];
		}
		if(sign==-1)printf("-");
		for(k=j-1;k>=0;k--)printf("%c",result[k]);
		printf("\n"); 
	}
	return 0;
}