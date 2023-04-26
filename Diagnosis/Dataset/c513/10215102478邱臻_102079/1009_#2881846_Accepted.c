#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GCD(int a,int b)
{
    int m,n;
    m = (a>b)?a:b;
    n = (a>b)?b:a;
    if(n == 0) return m;
    else return GCD(n,m%n);
}
int main() {
	char str[1000];
	int n,i,j,count,k,z,a,len;
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++){  //每一行字符串 
		gets(str);
		count=0;
		len=strlen(str);
		for(j=0;j<len;j++){
			z=str[j];
			for(k=0;k<8;k++){
				if(z&1<<k)count++;
			}
		}  //记录每个字符1的个数 
		a=GCD(count,8*len);
		printf("%d/%d\n",count/a,8*len/a);
	}
	return 0;
}