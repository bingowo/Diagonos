#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int letter[26];
int cmp(const void* a,const void* b);
int main() {
	char alpha[26];
	char str[100][21];
	int flag,count,i,k;
	char c; 
	while(scanf("%s",alpha)!=EOF){
		for(i=0;i<26;i++){
			letter[alpha[i]-'A']=i;   //新的字母顺序 
		}
		getchar();
		count=0;k=0;
		do{
			c=getchar();
			if(c!=' ' && c!='\n'){
				str[count][k]=c;
				flag=1;k++;
			}
			else if(flag){
				str[count][k]='\0';
				count+=1;k=0;flag=0;
			}
		}while(c!='\n');     //输入第二行的单词 
		qsort(str,count,sizeof(str[0]),cmp);
		for(i=0;i<count;i++){
			printf("%s",str[i]);
			if(i==count-1)printf("\n");
			else printf(" ");
		}   //按照新的顺序输出单词 
	}
	return 0;
}
int cmp(const void* a,const void* b){
	char *s1,*s2;
	char letter1,letter2;
	s1=*(char(*)[21])a;s2=*(char(*)[21])b;
	while(*s1 && *s2){  //s2和s2都有意义 
		letter1=(*s1)>='a'?*s1-32:*s1;
		letter2=(*s2)>='a'?*s2-32:*s2;  //字母小写转大写
		if(letter[letter1-'A']!=letter[letter2-'A']){
			return (letter[letter1-'A']-letter[letter2-'A']);
		} 
		else {
			s1++;s2++;  //比较下一个字母 
		}
		if(*s1==0)return 1;  //第一个单词结束 
		else return -1;  //第二个单词结束 
	}
}