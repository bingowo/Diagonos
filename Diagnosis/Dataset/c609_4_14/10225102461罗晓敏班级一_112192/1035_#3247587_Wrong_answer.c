#include <stdio.h>
int f(char num[]){              //有重复字符返回1；否则0 
	int ret=0,i;
	for(i=0;num[i];i++){
		if(num[i]==num[i+1]){
			ret=1;
			break;
		}
	}
	return ret;
}
int main(){
	int t,i;scanf("%d",&t);
	for(i=0;i<t;i++){
		char num[101],num2[101];
		int q=0;
		scanf("%s",num);
		for(i=0;num[i];i++){
			if(num[i]!=num[i+1]){
				num2[q++]=num[i];
			}
		}
		while(f(num2)==1){
			for(i=0;num[i];i++){
				if(num[i]==num[i+1]){
					i++;
					continue;
				}else{
					num2[q++]=num[i];
				}
			}
		}
		num2[q]='\0';
		printf("%s",num2);	
		
	}
}