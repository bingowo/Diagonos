#include <stdio.h>
#include <stdlib.h>
#include<string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int number(char*str){
	int len,i=0,sum=0,flag=0;
	len=strlen(str);
	for(i=0;i<len;i++){
		if(str[i]>='0'&&str[i]<='9'){
		sum=sum*10+str[i]-'0';
		flag==1;}
	}
	if(flag==0) sum=-1;
	return sum;}
int strnumcmp(const void*a,const void*b){
int s1,s2;
char*str1,*str2;
str1=(char*)a;
str2=(char*)b;
s1=number(str1);
s2=number(str2);
if(s1==s2) return strcmp(str1,str2);
if(s1>s2) return 1;
if(s1<s2) return -1;
}
int main(int argc, char *argv[]) {
	int count=0,j;
	char str[100][40];
	while(scanf("%s",str[count])!=EOF)
	count++;
	qsort(str,count,sizeof str[0],strnumcmp);
	for(j=0;j<count-1;j++)
	printf("%s ",str[j]);
	printf("%s\n",str[count-1]);
	return 0;
}