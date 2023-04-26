#include<stdio.h>
#include<stdlib.h>
/*typedef struct{
	int len;
	char num[101];
}NUM;*/

int main(void)
{
	int T;
	scanf("%d",&T);

	for(int i = 0; i < T; i++){
		int in,pw;
		scanf("%d%d",&in,&pw);
		char out[105] = {'1'};
		for(int v = 1; v < 105; v++){
			out[v] = '\0';
		}

		for(int v = 0; v < pw; v++){
			int plus = 0;
			for(char* p = out; *p != '\0' || plus != 0;p++){
				int temp = ((*p == '\0'?'0':*p)-'0')*in;
				temp += plus;
				plus = temp/10;
				*p = temp%10+'0';
			}
		}
		char* p = out;
		for(; *p != '\0'; p++);

		printf("case #%d:\n",i);
		for(p--;p >= out; p--)
			putchar(*p);
		putchar('\n');
	}
	return 0;
}