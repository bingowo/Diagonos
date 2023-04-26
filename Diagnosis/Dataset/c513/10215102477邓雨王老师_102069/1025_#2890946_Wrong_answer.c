#include<stdio.h>
#include<string.h>
int cal(char s[]){
	int count=0;
	char *i=s;
	for(;*i!='\0';i++){
		int m=*i;
		if(strchr(s,m)==i){
			count++;
		}
	}
	return count;
}
int cmp(const void*i,const void*j){
	char *x,*y;
	x=(char*)i;
	y=(char*)j;
	if(cal(x)>cal(y)){
		return 1;
	}
	else if(cal(x)==cal(y)){
		return -1;
	}
	else{
		return strcmp(x,y);
	}
}
int main(){
	int chance;
	scanf("%d",&chance);
	int i;
	for(i=0;i<chance;i++){
		printf("case #%d:\n",i);
		int problems; //表示每一次输入的字符串数量
		int j;
		scanf("%d",&problems);
		char s[110][25];
		for(j=0;j<problems;j++){
			scanf("%s",s[j]);
		}
		qsort(s,problems,sizeof(s[0]),cmp);
		for(j=0;j<problems;j++){
			printf("%s\n",s[j]);
		} 
	}
}