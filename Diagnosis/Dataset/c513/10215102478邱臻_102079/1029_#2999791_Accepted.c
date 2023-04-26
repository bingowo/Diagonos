#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int cmp(const void*a,const void*b){
	char*p1,*p2;
	p1=(char*)a;p2=(char*)b;
	return *p1>*p2?1:-1;  //顺序排序 
}
int main() {
	int t,z,k,i,j;
	char s[210];
	scanf("%d",&t);
	getchar();
	for(i=0;i<t;i++){
		gets(s);  //输入一整行字符
		z=0;k=0;
		char s1[210];
		for(j=0;j<strlen(s);j++){
			if(s[j]>='A' && s[j]<='Z')s1[k++]=s[j];  //只记录字母字符 
		} 
		qsort(s1,k,sizeof(s1[0]),cmp);
		for(j=0;j<strlen(s);j++){
			if(s[j]>='A' && s[j]<='Z')s[j]=s1[z++];
		} 
		printf("case #%d:\n%s\n",i,s);
	}
	
	return 0;
}