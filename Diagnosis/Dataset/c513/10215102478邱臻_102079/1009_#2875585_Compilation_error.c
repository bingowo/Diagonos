#include <stdio.h>
#include <stdlib.h>

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
	char str[120];
	int n,i,j,count,k,z;
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++){  //每一行字符串 
		gets(str);
		j=0;count=0;z=0;
		while(str[j]!='\0'){
			for(k=0;k<8;k++){
				if(str[j]&(1<<k))count++;
				z++;
			}
			j++;
		}  //记录每个字符1的个数 
		a=GCD(count,z);
		printf("%d/%d\n",count/a,z/a);
	}
	return 0;
}