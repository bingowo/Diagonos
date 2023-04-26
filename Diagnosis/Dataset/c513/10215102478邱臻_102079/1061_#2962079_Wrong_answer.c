#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct string{
	int result;
	char str[16];
};
int cmp(const void* a,const void* b){
	struct string p1,p2;
	p1=*(struct string*)a;p2=*(struct string*)b;
	if(p1.result!=p2.result)return p1.result>p2.result?1:-1;
	else return strcmp(p1.str,p2.str);
}
int main() {
	struct string s[10000];
	int t,i,j,count,len;
	int number[100];
	int n[16];
	scanf("%d",&t);
	for(i=0;i<t;i++){
		for(j=0;j<100;j++)number[j]=0;
	    for(j=0;j<16;j++)s[i].str[j]='\0';  //初始化 
		scanf("%s",s[i].str);  //输入字符串
		count=0;len=strlen(s[i].str);
		for(j=0;j<len;j++){
			if(j==0 || s[i].str[j]==s[i].str[0])n[j]=1;
			else if(count==1)n[j]=0;
			else if(number[s[i].str[j]-'0']!=0){
				n[j]=number[s[i].str[j]-'0'];
			}
			else n[j]=count;
			if(!number[s[i].str[j]-'0']){  //是第一次出现 
				count++;number[s[i].str[j]-'0']=count;
				} 
		}   //将每个字符串转化为二进制数组 
		for(j=0;j<len;j++){
			s[i].result=s[i].result*count+n[j];  //计算结果
		}
	}
	qsort(s,t,sizeof(s[0]),cmp);
	for(j=0;j<t;j++)printf("%s\n",s[j].str);
	return 0;
}