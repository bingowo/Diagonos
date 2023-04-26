#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int signal;
	char inte[110];
	char deci[110];
	char numOrigin[110]; 
} NUM;

int cmp(const void *a, const void *b) {
	NUM *n1 = (NUM *)a; NUM *n2 = (NUM *)b;
	if (n1 -> signal != n2 -> signal)
		return n1 -> signal - n2 -> signal;
	else if (strlen(n1 -> inte) != strlen(n2 -> inte))
		if (n1 -> signal == 1) return strlen(n1 -> inte) - strlen(n2 -> inte);
		else return strlen(n2 -> inte) - strlen(n1 -> inte);
	else if (strlen(n1 -> inte) == strlen(n2 -> inte) && strcmp(n1 -> inte, n2 -> inte) != 0) {
		if (n1 -> signal == 1) return strcmp(n1 -> inte, n2 -> inte);
		else return strcmp(n2 -> inte, n1 -> inte);
	} else {
		if (n1 -> signal == 1) return strcmp(n1 -> deci, n2 -> deci);
		else return strcmp(n2 -> deci, n1 -> deci);
	}
}

int main(){
	int T;
	scanf("%d", &T);
	NUM *nums = (NUM *)malloc(sizeof(NUM)*T);
	
//	char **numsOrigin = (char **)malloc(sizeof(char *)*T);

	for (int i = 0; i < T; i++) { //数据载入与处理 
		char s[110];
		scanf("%s", s);
		
		int len = strlen(s);
		
//		char *p = (char *)malloc((len+1) * sizeof(char));
//		strcpy(p, s);
//		*(numsOrigin + i) = p;
//		printf("%s\n", *(numsOrigin + i)); 

		strcpy((nums+i) -> numOrigin, s);
		
		if(s[0] == '-') (nums+i) -> signal = -1; //记录符号信息 
		else (nums+i) -> signal = 1;
		
		if(s[0] == '-' || s[0] == '+') { //若有符号位，删除符号位 
			for(int j = 1; j < len; j++) s[j-1] = s[j]; 
			len--;
			s[len] = '\0';
		}
		//printf("%s\n",s);
		
		int dotPos = -1;
		for (int k = 0; k < len; k++) { //记录小数点位置 
			if (s[k] == '.') dotPos = k;
		}
		
		if (dotPos == -1) strcpy((nums+i) -> inte, s); //记录整数部分 
		else { strncpy((nums+i) -> inte, s, dotPos); (nums+i) -> inte[dotPos] = '\0'; }
		
		if (dotPos != -1) { //记录小数部分
			int m = 0;
			for(int l = dotPos+1; l < len; l++) { (nums+i) -> deci[m++] = s[l];}
			(nums+i) -> deci[m] = '\0';
		} else { strcpy((nums+i) -> deci, "N"); }
		
		//printf("[%d] %d %s %s\n%s\n", i, (nums+i) -> signal, (nums+i) -> inte, (nums+i) -> deci, (nums+i) -> numOrigin);
	}
	
	qsort(nums, T, sizeof(NUM), cmp);
	
	for (int j = 0; j < T; j++) printf("%s\n", (nums+j) -> numOrigin);
	
}