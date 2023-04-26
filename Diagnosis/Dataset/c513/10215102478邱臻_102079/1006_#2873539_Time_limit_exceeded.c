#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int zhishu(int r){
	int i,result=1;
	for(i=1;i<=r;i++){
		result*=3;
	}
	return result;
}

int main() {
	int t,i,j,x,num,r;
	char str[10000];
	int result;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%s",str);
		j=0;num=0;result=0;
		while(str[j]!='\0'){
			num++;
		}  //计算字符串的位数
		r=num-1;
		for(j=0;j<num;j++,r--){
			if(str[j]=='-')x=-1;
			else{
				x=(int)str[j];
			}  //用正整数表示字符 
			result+=x*zhishu(r); 
		} 
		printf("case #i:\n%d\n",i,result);
		
	}
	return 0;
}