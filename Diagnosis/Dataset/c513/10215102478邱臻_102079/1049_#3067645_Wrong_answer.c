
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
struct alphabet{
	char word[26];
};
int cmp(const void*a,const void *b){
	struct alphabet p1,p2;
	p1=*(struct alphabet*)a;p2=*(struct alphabet*)b;
	return strcmp(p1.word,p2.word);
}
int main()
{
    int t,i,j,flag,count,k;
    char s[1000];
    char c;
    struct alphabet a[1000];
    scanf("%d",&t);
    c=getchar();
    for(i=0;i<t;i++){
    	gets(s);
    	flag=0;count=0;k=0;
    	for(j=0;j<strlen(s);j++){
	    	if(!flag){
	    		if(j==0 || (isalpha(s[j]) && (isspace(s[j-1]) || ispunct(s[j-1])))){
	    			flag=1;a[count].word[k++]=s[j];	
				}
				//进入单词内部 
			}
			else if(flag){
				if(isalpha(s[j]) && j!=strlen(s)-1){
					if(j!=strlen(s)-1)a[count].word[k++]=s[j];
					else {
						a[count].word[k++]=s[j];
						a[count].word[k]='\0';
					    k=0;flag=0;count++;
					}
				}
				else {
					a[count].word[k]='\0';
					k=0;flag=0;count++;
				}  //结束一个单词 
			} 
		}  //统计单词个数
		qsort(a,count,sizeof(a[0]),cmp);
		printf("case #%d:\n",i);
		for(j=0;j<count;j++){
			if(j==0)printf("%s ",a[j].word);
			else {
				if(strcmp(a[j].word,a[j-1].word))printf("%s ",a[j].word);
			}
		}  //输出 
		printf("\n");
	}
    return 0;
}