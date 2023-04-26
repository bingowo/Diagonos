#include <stdio.h>
#include <string.h>

void ter2dec(char *inp, int inplen);
int threepow(int n);

int main(){
	char inp[30] = {0};
	int inplen;
	scanf("%s", inp);
	inplen = strlen(inp);
	ter2dec(inp, inplen);
	return 0;
}

int threepow(int n){
	int ret = 1;
	int time = n;
	while(time > 0){
		ret *= 3;
		time--;
	}
	//printf("3^(%d) = %d", n, ret);
	return ret;
}

void ter2dec(char *inp, int inplen){
	
	//处理整数部分
	int intlen;
	for(intlen = 0; inp[intlen] != '.' && intlen < inplen; intlen++);
	long long int ret = 0;
	for(int j = intlen - 1; j > -1; j--){
		if (inp[j] == '2'){
			ret += (-1) * threepow(intlen - 1 - j);
		}else if(inp[j] == '0'){
			ret += (0) * threepow(intlen - 1 - j);
		}else{
			ret += (1) * threepow(intlen - 1 - j);
		}
	}
	
	//处理小数部分
	int fltlen = inplen - intlen - 1;
	//printf("fltlen:%d\n", fltlen);
	long long int demo = threepow(fltlen); //最大分母：3^(n)
	long long int nume = 0;
	for(int k = fltlen - 1; k > -1; k--){
		if (inp[intlen + 1 + k] == '2'){
			nume += (-1) * threepow(fltlen - 1 - k);
		}else if(inp[intlen + 1 + k] == '0'){
			nume += (0) * threepow(fltlen - 1 - k);
		}else{
			nume += (1) * threepow(fltlen - 1 - k);
		}
	}
	
//	printf("int:%d\n", ret);
//	printf("nume/demo: %d/%d\n", nume, demo);
	
	if(nume*demo < 0 && ret != 0){
		ret -= 1;
		nume = demo + nume;
	}else if(ret < 0){
		ret += 1;
		nume = demo - nume;
	}
	
//	printf("int:%d\n", ret);
//	printf("nume/demo: %d/%d\n", nume, demo);
	
	if (intlen == inplen){
		printf("%lld", ret);
	}else if(ret == 0){
		printf("%lld %lld",nume, demo);
	}else{
		printf("%lld %lld %lld",ret, nume, demo);
	}
	
}