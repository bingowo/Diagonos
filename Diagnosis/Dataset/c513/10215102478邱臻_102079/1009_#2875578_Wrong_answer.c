#include <stdio.h>
#include <stdlib.h>


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
		printf("%d/%d\n",count,z);
	}
	return 0;
}