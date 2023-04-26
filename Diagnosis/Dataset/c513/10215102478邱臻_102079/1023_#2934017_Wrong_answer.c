#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int number(char* str);
int strnumcmp(const void* a,const void* b){
	int n1,n2;
	char *s1,*s2;
	s1=*(char(*)[31])a;s2=*(char(*)[31])b;   //字符串本身 
	n1=number(s1);n2=number(s2);  //提取的数字
	if(n1==n2){
		return strcmp(s1,s2);
	} 
	else return n1-n2;
} 
int number(char* str){
	int len=strlen(str),i,flag=0,sum=0;
	for(i=0;i<len;i++){
		if(str[i]>='0' && str[i]<='9'){
			sum=sum*10+(str[i]-'0');
			flag=1;
		}
		if(!flag)sum=-1;
		return sum;
	}    
}    //提取字符串末尾数字 
int main() {
	char str[110][31];
	int count=0,i;
	while(scanf("%s",str[count])!=EOF){
		count++;
	}   //输入字符串
	qsort(str,count,sizeof(str[0]),strnumcmp);
	for(i=0;i<count;i++){
		printf("%s%c",str[i],i==count-1?'\n':' ');
	} 
	
	return 0;
}