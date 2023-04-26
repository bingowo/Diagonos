#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int list[123]={};
struct words{
	char word[27];
};
int cmp(const void*a,const void*b){
	struct words p1,p2;
	int len,i;
	p1=*(struct words*)a;p2=*(struct words*)b;
	len=strlen(p1.word)>=strlen(p2.word)?strlen(p2.word):strlen(p1.word);
	for(i=0;i<len;i++){
		if(list[p1.word[i]]>list[p2.word[i]])return 1;
		else if(list[p1.word[i]]<list[p2.word[i]]) return -1;
	}
	if(strlen(p1.word)>=strlen(p2.word))return 1;
	else return -1;
}
int main() {
	struct words a[100];
	char s[27];
	char c;
	int i,j,flag,k;
	while(scanf("%s",s)){
		for(i=0;i<123;i++)list[i]=0;
		flag=1;k=0;
		for(j=0;j<strlen(s);j++){
			list[s[j]]=flag;list[s[j]+32]=flag;
			flag++;
		}  //新的字母表顺序
		do{
			scanf("%s",a[k].word);
			k++;
		}while((c=getchar())!='\n');  //储存单词
		qsort(a,k,sizeof(a[0]),cmp); 
		for(j=0;j<k;j++){
			printf("%s",a[j].word);
			if(j!=k-1)printf(" ");
			else printf("\n");
		}
    }
	return 0;
}