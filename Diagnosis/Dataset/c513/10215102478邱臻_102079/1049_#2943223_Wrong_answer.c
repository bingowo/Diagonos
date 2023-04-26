#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int cmp(const void* a,const void* b){
	char *p1,*p2;
	p1=*(char(*)[26])a;p2=*(char(*)[26])b;
	while(*p1 && *p2){
		if(*p1!=*p2)return *p1<*p2?-1:1;
		else {
			p1++;p2++;
		}
	}
	if(*p1)return 1;
	else return -1;
}
int main() {
	int t,i,j,x,q,p,flag,count,z,k;
	char c;
	char s[501][26],s1[501][26];
	scanf("%d",&t);
	getchar();
	j=0;k=0;
	for(i=0;i<t;i++){  //每一行不同的文本
        flag=0;count=0;
        for(j=0;j<501;j++){
        	for(k=0;k<26;k++){
        		s[j][k]='\0';s1[j][k]='\0';
			}
		}
		j=0;k=0;
		while((c=getchar())!='\n'){
			if(isalpha(c)){  //是单词中的字母
			    if(!flag){   //一个新的单词
				    s[j][k++]=c;
					flag=1;
				}
				else if(flag)s[j][k++]=c;  //原单词 
			}
			else if(c!='\n'){   //单词的结束
			    s[j][k]='\0';  //单词成为一个字符串 
				flag=0;k=0;j++;count++;
			}
		}
		p=0;
		for(z=0;z<=count;z++){
			flag=0;
			for(x=0;x<=p;x++){
				if(strcmp(s[z],s1[x])==0)flag=1;
			}
			if(flag==0)strcpy(s1[p++],s[z]);
		}
		qsort(s1,p,sizeof(s1[0]),cmp);
		for(q=0;q<p;q++){
			printf("%s%c",s1[q],q<p-1?' ':'\n');
		}
	}
	
	return 0;
}