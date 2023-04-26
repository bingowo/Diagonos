#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n,r,j,x,i,y;
	char result[100]; 
	char num[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	scanf("%d%d",&n,&r);
	if(n==0)printf("0");
	else {
		for(i=0;i<100;i++)result[i]='0';  //初始化数组 
		i=0;
		while(n!=0){
			if((n-n/r*r)<0){
				y=n/r+1;x=n-r*y;
			}
			else {
				y=n/r;x=n-r*y;
			}
			n=y;
			result[i++]=num[x];
		}  //转化为r进制 
		for(j=i-1;j>=0;j--)printf("%c",result[j]);
    }
	return 0;
}