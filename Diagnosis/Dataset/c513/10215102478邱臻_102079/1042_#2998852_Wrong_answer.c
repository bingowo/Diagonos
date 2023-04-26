#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct str{
	char a[17];
};
int cmp1(const void*a,const void*b){
	char* p1,*p2;
	p1=(char*)a;p2=(char*)b;
	return *p1>*p2?1:-1;  //正序排列 
}
int cmp2(const void*a,const void*b){
	struct str p2,p1;
	p1=*(struct str*)a;p2=*(struct str*)b;
	return strcmp(p1.a,p2.a);
}
int main(int argc, char *argv[]) {
	long long int sign[53]={};
	long long int t,x,y,i,j,k,n,z;
	char s[17],s1[17],s2[17];
	scanf("%lld",&t);
	for(i=0;i<t;i++){
		struct str result[1000];
		k=0;
		for(j=0;j<53;j++)sign[j]=0;  //数组初始化 
		strcpy(s1,"0");strcpy(s2,"0");
		scanf("%s",s);  //输入字符串
		for(j=0;j<strlen(s);j++){
			if(!sign[s[j]-'A']){
				sign[s[j]-'A']=1;  //结束后为1
				s1[k++]=s[j]; 
//				result[k][0]=s[j];result[k++][1]='\0';  //对单个字符的记录  
			}  //k是不同字符数 
		}
		qsort(s1,k,sizeof(s1[0]),cmp1);  //按字典顺序排序 
		z=0;n=0;
		for(x=0;x<k;x++){
		    z=0;
			for(y=x;y<k;y++){
				s2[z++]=s1[y];s2[z]='\0';
				strcpy(result[n].a,s2);  //记录字符串 
				n++;
			}  //一次循环结束
			strcpy(s2,"0");  //初始化字符串 
		}
		qsort(result,n,sizeof(result[0]),cmp2);
		printf("case #%d:\n",i);
		for(j=0;j<n;j++)printf("%s\n",result[j].a);
	}
	return 0;
}