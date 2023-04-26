#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int t,i,j,z,count,a,x,y,b,k,max=0;;
	int num[153];
	char s[51];
	scanf("%d",&t);
	for(i=0;i<t;i++){
		for(j=0;j<153;j++){num[j]=0;}
		scanf("%s",s);
		y=0;z=0;
		for(j=strlen(s)-1;j>=2;j--){
			x=s[j]-'0';z=0;max=count;count=0;k=0;a=1;b=1;
			while(b!=0 || count<max || a!=0){
				y=num[k++];
				a=(x*10+y)/8;b=(x*10+y)%8;
				num[z++]=a;x=b;count++;
			}
		}
		printf("case #%d:\n0.",i);
		for(z=0;z<count;z++)printf("%d",num[z]);
		printf("\n");
	}
	return 0;
}