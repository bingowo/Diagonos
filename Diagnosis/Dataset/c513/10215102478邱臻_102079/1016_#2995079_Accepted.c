#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	char alpha[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int n,r,i=0,j,a,b;
	char result[1000];
	scanf("%d%d",&n,&r);
	if(n==0)printf("0");
	else {
	while(n!=0){
		a=n%r;b=n/r;
		if(a<0){
			b++;a=n-(b*r);
		}
		n=b;
		result[i++]=alpha[a];
	}
	for(j=i-1;j>=0;j--)printf("%c",result[j]);
    }
	return 0;
}