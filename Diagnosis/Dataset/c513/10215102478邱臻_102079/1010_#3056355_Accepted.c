#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	char n[501],num[11];
	int count,i,x=0,flag=0,z,a,j;
	scanf("%s",n);  //输入字符串
	count=strlen(n);
	for(i=0;i<11;i++)num[i]='0';
	i=0;
	while(count!=0){
		a=count%2;count=count/2;
		num[i++]=a+'0';
	}count=strlen(n);
	printf("0001");
	for(i=9;i>=0;i--)printf("%c",num[i]);  //输出字符个数的二进制 
	for(i=0;i<count;i++){
		if((i+1)%3==0){
			x=x*10+n[i]-'0';
			z=0;
			for(j=0;j<11;j++)num[j]='0';
			if(x==0)printf("0000000000");
			else {
			while(x!=0){
				a=x%2;x=x/2;
				num[z++]=a+'0';
			}
			for(j=9;j>=0;j--)printf("%c",num[j]);
		}
			x=0;flag=0;
		}  //转换成二进制
		else if(i!=(count-1)){x=x*10+n[i]-'0';flag++;}  //分组三个数字
		else if((i+1)%3!=0 && i==count-1){
			for(j=0;j<11;j++)num[j]='0';
			x=x*10+n[i]-'0';flag++;z=0;
			if(flag==2){
				while(x!=0){
					a=x%2;x=x/2;
					num[z++]=a+'0';
				}
				for(j=6;j>=0;j--)printf("%c",num[j]);
			}
			else if(flag==1){
				while(x!=0){
					a=x%2;x=x/2;
					num[z++]=a+'0';
				}
				for(j=3;j>=0;j--)printf("%c",num[j]);
			}
		} 
	} 
	return 0;
}