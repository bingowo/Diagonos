#include <stdio.h>
#include <string.h>

void ter2dec(char *inp, int inplen);
int threepow(int n);

int main(){
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		char inp[30] = {0};
		int inplen;
		scanf("%s", inp);
		inplen = strlen(inp);
		printf("case #%d\n", i);
		ter2dec(inp, inplen);
	}
	return 0;
}

int threepow(int n){
	int ret = 1;
	int time = n;
	while(time){
		ret *= 3;
		time--;
	}
	//printf("3^(%d) = %d", n, ret);
	return ret;
}

void ter2dec(char *inp, int inplen){
	int ret = 0;
	for(int j = inplen - 1; j > -1; j--){
		if (inp[j] == '-'){
			ret += (-1) * threepow(inplen - 1 - j);
		}else if(inp[j] == '0'){
			ret += (0) * threepow(inplen - 1 - j);
		}else{
			ret += (1) * threepow(inplen - 1 - j);
		}
	}
	printf("%d", ret);
}