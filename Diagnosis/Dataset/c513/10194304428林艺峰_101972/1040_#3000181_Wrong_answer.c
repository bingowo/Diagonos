#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int ABO[4][4][4] = {
1, 0, 0, 1,  1, 1, 1, 1,  1, 1, 1, 0,  1, 0, 0, 1,
1, 1, 1, 1,  0, 0, 1, 1,  1, 1, 1, 0,  0, 0, 1, 1,
1, 1, 1, 0,  1, 1, 1, 0,  1, 1, 1, 0,  1, 0, 1, 0,
1, 0, 0, 1,  0, 0, 1, 1,  1, 0, 1, 0,  0, 0, 0, 1
};
int ans[4];
char *type[] = {"A", "AB", "B", "O"};
int read(){
	char str[110];
	scanf("%s", &str);
	if(!strcmp(str, "A"))	return 0;
	else if(!strcmp(str, "AB"))	return 1;
	else if(!strcmp(str, "B"))	return 2;
	else if(!strcmp(str, "O"))	return 3;
	else	return 4;
}
int main(){
	int father = read(), mother = read(), child = read(), cnt = 0, i;
	if(father == 4){
		for(i = 0; i < 4; ++i){
			if(ABO[i][mother][child])	ans[cnt++] = i;
		}
		if(cnt){
			printf("{");
			for(i = 0; i < cnt - 1; ++i){
				printf("%s,", type[ans[i]]);
			}
			printf("%s}", type[ans[cnt-1]]);
		}
		else{
			printf("impossible");
		}
		printf(" %s %s", type[mother], type[child]);
	}
	else if(mother == 4){
		for(i = 0; i < 4; ++i){
			if(ABO[father][i][child])	ans[cnt++] = i;
		}
		printf("%s", type[father]);
		if(cnt){
			printf(" {");
			for(i = 0; i < cnt - 1; ++i){
				printf("%s,", type[ans[i]]);
			}
			printf("%s}", type[ans[cnt-1]]);
		}
		else{
			printf(" impossible");
		}
		printf(" %s", type[child]);
	}
	else if(child == 4){
		for(i = 0; i < 4; ++i){
			if(ABO[father][mother][i])	ans[cnt++] = i;
		}
		printf("%s %s", type[father], type[mother]);
		if(cnt){
			printf(" {");
			for(i = 0; i < cnt - 1; ++i){
				printf("%s,", type[ans[i]]);
			}
			printf("%s}", type[ans[cnt-1]]);
		}
		else{
			printf(" impossible");
		}
	}
	return 0;
}