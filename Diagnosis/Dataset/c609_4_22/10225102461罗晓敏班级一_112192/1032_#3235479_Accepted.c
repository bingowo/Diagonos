#include <stdio.h>
char *p;
int f(char* a){
	int ret=1;
	while(*a!=*(a+1)&&*(a+1)){
		ret++;
		a++;
	}
	if(*a==*(a+1)||*(a+1)==0){
		p=++a;
	}
	return ret;
}
int main(){
	char num[51];
	scanf("%s",num);
	p=num;
	int ret=-1,temp;
	while(*p){
		temp=f(p);
		if(temp>ret){
			ret=temp;
		}
	}
	printf("%d",ret);
} 