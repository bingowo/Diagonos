#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct string{
	int count;
	char *letter;
};
int cmp(const void* a,const void* b){
	struct string *p1,*p2;
	p1=*(struct string *)a;p2=*(struct string *)b;
	if(p1.count!=p2.count)return p1.count<p2.count?1:-1;
	else return strcmp(p1.letter,p2.letter);
}
int main() {
	int T,i,j,z,k,n;
	char s[21];
	int judge[26]={0};
	struct string str[100];
	scanf("%d",&T);  //输入问题数
	for(k=0;k<T;k++){  //一组问题
	    scanf("%d",&n);  //字符串个数 
		for(i=0;i<n;i++){   //每一行的字符串 
			for(j=0;j<26;j++)judge[j]=0;
			scanf("%s",s);
			strcpy(str[i].letter,s);  //放入 结构体
			str[i].count=0;
			for(j=0;j<strlen(s);j++){
				if(judge[s[j]-'A']==0){
					str[i].count++;
					judge[s[j]-'A']=1;
				}  //有新字符出现 
			}  //统计字符个数 
		}
		qsort(str,n,sizeof(str[0]),cmp);
	}
		printf("case #%d:\n",i);
		for(z=0;z<n;z++){
			printf("%s",str[z].letter);
		} 
	} 
	return 0;
}
