#include<stdio.h>
#include<string.h>
int main(){
	char s[101];
	int key=0;   //key类似于一个判断0的开关的作用
	scanf("%s",&s);
	int i;
	int max=0;
	int sum=0;
	for(i=0;i<strlen(s);i++){
		if(key==1&&isdigit(s[i])){
			sum++;
			if(max<sum) max=sum;
		}
		else if(key==1&&isdigit(s[i])==0){
			sum=0;
			key=0;
		}
		else if(key==0&&s[i]>='1'&&s[i]<='9'){
			key=1;
			sum++;
		}
	}
	printf("%d",max);
	
}