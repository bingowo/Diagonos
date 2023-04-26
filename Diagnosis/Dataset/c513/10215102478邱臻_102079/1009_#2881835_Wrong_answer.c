#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GCD(int m,int n)
{
    int a;
    if(n>m){a=n;n=m;m=a;}
    if(m%n==0)return n;
    else if(m%n!=0){
        n=m%n;
        return(GCD(m,n));
    }
    //TODO: your function definition
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
				if(z&(1<<k))count++;
			}
		}  //记录每个字符1的个数 
		a=GCD(count,8*len);
		printf("%d/%d\n",count/a,8*len/a);
	}
	return 0;
}