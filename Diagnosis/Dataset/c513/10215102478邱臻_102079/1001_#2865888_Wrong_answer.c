#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main() {
	int T,i,j=0;
	int temp=1;
	int k,x;
	int n,r;
	char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int num[32];
	scanf("%d",&T);
	for(i=0;i<T;i++){
		scanf("%d %d",&n,&r);
		if(n<0){temp=0;n=-n;}  //负数 
		else if(n>=0)temp=1;
		do
		{
			x=n%r;n=n/r;
			num[j]=x;
			j++;
		}while(n);
		if(temp==0)printf("-");
		for(k=j-1;k>=0;k--)printf("%c",table[num[k]]);	
		printf("\n");
	}
	return 0;
}