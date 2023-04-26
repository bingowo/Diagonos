#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void bin(int n,char *s){
	int a,i=0;
	while(n!=0){
		a=n%2;n=n/2;
		s[i++]=a+'0';
	}
}
int main() {
	int t,i,j,count,x,y;
	char binx[33],biny[33];
	scanf("%d",&t);
	for(i=0;i<t;i++){
		count=0;
		for(j=0;j<33;j++){binx[j]='0';biny[j]='0';}
		scanf("%d%d",&x,&y);
		bin(x,binx);bin(y,biny);
		for(j=0;j<33;j++){
			if(binx[j]!=biny[j])count++;
		}
		printf("%d\n",count);
	}
	return 0;
}