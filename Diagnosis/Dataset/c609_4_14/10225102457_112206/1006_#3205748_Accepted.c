#include<stdio.h>
#include<string.h>
int mark(char *str,int *out)
{
	int strl = strlen(str);
	int alnum = strl;
	int num = 0;
	for(int test = 0; test < strl; test++){
		for(int find = test+1; find < strl; find++){
			if(str[find] == str[test] && str[find] != '\b'){
				out[find] = num;
				str[find] = '\b';
				alnum--;
			}
		}
		if(str[test] != '\b'){
			out[test] = num;
		    num++;
		}
	}
	return alnum;
}

int main(void)
{
	int T;
	scanf("%d",&T);
	
	for(int i = 0; i < T; i++){
		char input[61];
		scanf("%s",input);
		
		int output[strlen(input)];
		int r = mark(input,output);
		if(r == 1) r = 2;
		long long out = 0;
		
		for(int n = 0; n < strlen(input); n++){
			int v = 0;
			if(output[n] == 1) v = 0;
			else if(output[n] == 0) v = 1;
			else v = output[n];
			
			out = out*r+v;
		}
		printf("case #%d:\n",i);
		printf("%lld\n",out);
	}
	return 0;
}