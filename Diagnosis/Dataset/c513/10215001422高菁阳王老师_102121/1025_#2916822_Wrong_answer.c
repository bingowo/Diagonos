#include <stdio.h>
#include <stdlib.h>
#include<string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int number(char *s){
int cnt=0;
char flag[90]={0};
while(*s){
	if(*s>=0||*s<=90){
		if(flag[*s]==0){
		cnt++;
		flag[*s]=1;
		}
	}s++;
}return cnt;
	
}
int cmp(const void*a,const void*b){
	int s1,s2;
char*str1,*str2;
str1=(char*)a;
str2=(char*)b;
s1=number(str1);
s2=number(str2);
if(s1==s2) return strcmp(str1,str2);
if(s1>s2) return -1;
if(s1<s2) return 1;
	
}
int main(int argc, char *argv[]) {
	int n,m,k;
	char s[100][20];
	scanf("%d\n",&n);
	for(k=0;k<n;k++){
		printf("case #%d:\n",k);
		scanf("%d\n",&m);
		for(int i=0;i<m;i++){
			scanf("%s\n",s[i]);}
	qsort(s,m,sizeof(s[0]),cmp);
	for(int i1=0;i1<m;i1++)
	printf("%s\n",s[i1]);
	}
	return 0;
}