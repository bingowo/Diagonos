#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
	char c[10000];
	int num;
}STR;
int count(char*c){
    int p[27]={0};
	int co=0;
	for(int v=0;v<strlen(c);v++){
		p[c[v]-'A']++;
	}
	for(int l=0;l<27;l++){
		if(p[l]>0) co++;
	}
	return co;
}
int cmp(const void*a,const void*b){
	int a1=((STR*)a)->num,b1=((STR*)b)->num;
	if(a1==b1) return strcmp(((STR*)a)->c,((STR*)b)->c);
	else return (b1>a1)?1:-1;
} 
int main(){
	int T,N;
	STR str[10000];
	scanf("%d\n",&T);
	for(int i=0;i<T;i++){
		scanf("%d\n",&N);
	for(int j=0;j<N;j++){
		scanf("%s\n",&str[j].c);
		str[j].num=count(str[j].c);
	}
	qsort(str,N,sizeof(STR),cmp);
	printf("case #%d:\n",i);
	for(int k=0;k<N;k++){
		printf("%s\n",str[k].c);
	}
    
}
return 0;
}