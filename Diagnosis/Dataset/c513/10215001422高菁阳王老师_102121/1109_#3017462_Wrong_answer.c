#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n,k;
	scanf("%d",&n);
	for(k=0;k<n;k++){
		int i,flag=0,a,first=0;
		printf("case #%d:\n",k);
		for(i=8;i>=0;i--){
			scanf("%d",&a);
			if(a&&!flag){flag=1;first=i;}
			if(first==0&&i==0) printf("%d",a);
			if(first!=0&&a!=0){
				if(a<0) printf("-");
				if(a>0&&i!=first) printf("+");
				if((int)fabs(a)!=1||i!=0) printf ("%d",(int)fabs(a));
				if(i>0) printf("x");
				if(i>1) printf("^%d",i);
			}
		}printf("\n");
	}
	return 0;
}