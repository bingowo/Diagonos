#include<stdio.h>
#include<string.h>
int cmp(const void*a,const void*b){
	char *x,*y;
	x=(char*)a;
	y=(char*)b;
	return strcmp(x,y);
}
int main(){
	int chance;
	scanf("%d\n",&chance);
	int i;
	for(i=0;i<chance;i++){
		char s[501];
		int t=0,p=0;  //t表示c的一维参数，p表示二维参数 
		char c[100][15];
		gets(s);
		int j;
		for(j=0;j<strlen(s);j++){
		if(islower(s[j])){
		c[t][p++]=s[j];
		if(islower(s[j+1])==0){
		c[t][p]='\0';
		p=0;
		t++;
		}
	}
	}
		qsort(c,t,sizeof(c[0]),cmp);
		printf("case #%d:\n",i);
		char c1[100][15];
		int t1=0;
		for(j=0;j<t;j++){
			printf("%s ",c[j]);
		}
		printf("\n");
	}
} 