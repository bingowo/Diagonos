#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int gcd(int a,int b){
	int m,n;
	m=a>b?a:b;n=a<b?a:b;
	if(n==0)return m;
	else return gcd(n,m%n);
}
int main(int argc, char *argv[]) {
	int n,i,j,k,count,len,a;
	char s[121];
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++){
		gets(s);  //输入字符
		count=0;len=8*strlen(s);  //总的字节数
		for(j=0;j<strlen(s);j++){
			for(k=0;k<8;k++){
				if(s[j]&(1<<k))count++;
			}
		}  //每个字符中1的个数
		a=gcd(count,len);
		printf("%d/%d\n",count/a,len/a); 
	}
	return 0;
}