#include<stdio.h>
#include<string.h>
int find(char a, char*b){
	int len = strlen(b);
	for(int i=len-1;i>=0;i--){
		if(a==b[i])return 0;
	}//找到一样返回0，没找到返回1
	return 1;
}
void csh(char *a){
	int len = strlen(a);
	for(int i = 0;i<len;i++){
		a[i] = '\0';
	}//初始化函数
}
int fi(char a, char *b){//返回a在数组b中的位置0-->1,1-->0,2-->2...
	int ret = 0;
	while(a!=b[ret]){
		ret++;
	}
	switch(ret){
		case 0:
			ret = 1;
			break;
		case 1:
			ret = 0;
			break;
		default:
			break;
	}
	return ret;
}
int main(){
	int num = 0;//输入总数
	char get[60] = {'\0'};
	char in[62] = {'\0'};
	int jz = 0;//进制
	int ret = 0;
	int sam[10] = {0};//最小整数和
	scanf("%d", &num);
	for(int i=0;i<num;i++){
		scanf("%s", &get);
		int len = strlen(get);
		for(int j=0;j<len;j++){
			int sb = find(get[j], in);
			if(sb==1)in[jz++] = get[j];
		}
		int ge = 1;
		for(int j=0;j<len;j++){
			ge *= jz;
		}
		for(int j = 0;j<len;j++){
			int nu = fi(get[j], in);
			ret += nu*ge;
			ge /= jz;
		}
		sam[i] = ret;
		jz = 1;//初始化
		ge = 1;
		csh(in);
		csh(get);
	}
	for(int i=0;i<num;i++){
		printf("case #%d:\n", i);
		printf("%d", sam[i]);
	}
	return 0;
}