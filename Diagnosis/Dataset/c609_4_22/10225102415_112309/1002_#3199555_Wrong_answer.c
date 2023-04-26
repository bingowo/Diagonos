#include <stdio.h>

void NonRepBin(int);
int main(){
	int T, n;
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		printf("case #%d:\n",i);
		scanf("%d", &n);
		NonRepBin(n);
	}
	return 0;
}
void NonRepBin(int n){
	//将十进制数转为二进制表示
	int bin[40];
	int i = 0;
	//printf("Reversed Binary:");
	while(n){
		bin[i] = n % 2;
		n /= 2;
		//printf("%d",bin[i]);
		i++;
	}
	//printf("\n");
	//计算最长非重复子串长度 
	int len = --i;
	int max = 1;
	int nonrep = 1;
	int flag = 0;
	for(int j = 1; j < len; j++){
		if(bin[j] != bin[j-1]){
			nonrep++;
			flag = 0;
		}else{
			if(nonrep > max) max = nonrep;
			nonrep = 1;
			flag = 1;
			//printf("Flag = 1\n");
		}
		//printf("NonRep:%d\n",nonrep);
	}
	if(flag == 0) max = ++nonrep;
	printf("%d\n",max); 
}