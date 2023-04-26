#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double times[26];
int cmp(const void*a,const void*b){
	char *p1,*p2;
	int i,j;
	p1=(char*)a,p2=(char*)b;
	if(*p1>='a' && *p1<='z')i=*p1-'a';  //p1小写 
	else if(*p1>='A' && *p1<='Z')i=*p1-'A';  //大写 
	if(*p2>='a' && *p2<='z')j=*p2-'a';
	else if(*p2>='A' && *p2<='Z')j=*p2-'A';
	if(i!=j)return times[i]>times[j]?-1:1;
	else return *p1>*p2?-1:1;  //按大小写排序 
} 
int main() {
	int t,i,j;
	char s[101]; 
	scanf("%d",&t);
	for(i=0;i<t;i++){
		for(j=0;j<26;j++)scanf("%lf",&times[j]);  //记录使用频率
		getchar();
		scanf("%s",s);  //记录字符串
		qsort(s,strlen(s),sizeof(s[0]),cmp);
		printf("case #%d:\n%s\n",i,s);
	}
	return 0;
}