#include<stdio.h>
#include<string.h>
int main(){
	char inpt[60] = {'\0'};
	int num = 0;
	int len;//读入字符串长度，便于遍历
	char ge;//读入前面的符号
	int lasnum;
	gets(inpt);
	len = strlen(inpt);
	ge = inpt[0];
	num = lasnum = 1;
	for(int i=1;i<len;i++){
		if(ge==inpt[i]){//比较+重置计数num
			if(num>lasnum){
				lasnum = num;
			}
			num = 1;
		}
		else{//不一样，计数num自增
			num++;
		}
		ge = inpt[i];
	}
	printf("%d", lasnum);
	return 0;
}