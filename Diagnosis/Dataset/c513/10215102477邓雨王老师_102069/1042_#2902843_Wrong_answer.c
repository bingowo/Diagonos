#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 25
void combination_op(char* pstr, char* output, int m);
void combination(char* pstr);
int cmp(const void*a,const void*b){
	char *x,*y;
	x=(char*)a;
	y=(char*)b;
	return strcmp(x,y);
}
void sort(char s[],char c[]){
	int i;
	int length=strlen(s);
	int j=0;
	for(i=0;i<length;i++){
		int m=s[i];
		if(strchr(s,m)==&s[i]) c[j++]=s[i];
	}
	c[j]='\0';
}

int main(){
//	char* pstr = "";
    int chance;
    scanf("%d",&chance);
    int i;
    for(i=0;i<chance;i++){
    	printf("case #%d:\n",i);
	char pstr[20];
	char c[20];
	scanf("%s",&pstr);
	sort(pstr,c);
	qsort(c,strlen(c),sizeof(c[0]),cmp);
	combination(c);

/*	if(fp != NULL){
		while(fgets(pstr, sizeof(pstr), fp) != NULL);
		combination(pstr);
	}
*/
	return EXIT_SUCCESS;}
}

void combination(char* pstr){
	int cap;

	if(pstr == NULL){
		printf("空串！\n");
		return;
	}
	for(cap = 1; cap <= (int)strlen(pstr); cap++){
		char output[MAX] = "";
		combination_op(pstr, output, cap);
	}
}
void combination_op(char* pstr, char* output, int m){
	/*
	**当剩下的字符恰好够组合时，直接全部复制到输出字串中。
	*/
	if((int)strlen(pstr) == m){
		strcat(output, pstr);
		printf("%s\n",output);
		*(output + (int)strlen(output) - m - 1) = '\0';//回溯
		return;
	}
	/*
	**输出串已满时
	*/
	if(m <= 0){
		printf("%s\n", output);	
		*(output + (int)strlen(output) - 1) = '\0';//回溯
	}else{
		//添加当前字符
		strncat(output, pstr,1);
		combination_op(pstr+1, output, m-1);
		//不添加当前字符
		combination_op(pstr+1, output, m);
	}
}
