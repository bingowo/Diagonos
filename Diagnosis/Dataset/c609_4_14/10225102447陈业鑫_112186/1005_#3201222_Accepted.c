#include<stdio.h>
#include<string.h>
int tothree(char c){
	if(c == '-')return -1;
	if(c == '0')return 0;
	return 1;
}
int main(){
	int num;
	char gech[10][20] = {'\0'};
	int ret[10] = {0};
	scanf("%d", &num);
	for(int i=0;i<num;i++){
		scanf("%s", &gech[i]);
	}
	long long int tore = 1;
	for(int i=0;i<num;i++){
		for(int j=strlen(gech[i])-1;j>=0;j--){
			ret[i] += tore*tothree(gech[i][j]);
			tore *= 3;
		}
		tore = 1;
	}
	for(int i=0;i<num;i++){
		printf("case #%d:\n", i);
		printf("%d\n", ret[i]);
	}
	return 0;
}