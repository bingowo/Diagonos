#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct{
	int len;
	char s[21];
}str;
int cmp(const void* a,const void* b);
char tab[255];
int main(){
	char c;
	c = getchar();
	while(c != EOF){
		int cnt = 0;                   			//字符串个数 
		int len = 0;
		for(int i = 0;i < 52;i+=2){
			tab[c] = i;
			tab[c+'a'-'A'] = i + 1; 
			c = getchar();                     //最后读入换行符 
		}
		c = getchar();
		str* p = (str*)malloc(sizeof(str) * 101);
		while(c != '\n' && c != EOF){
			if(isspace(c)){
				p[cnt].s[len] = '\0';
				p[cnt].len = len;
				cnt++;
				len = 0;
			}
			else
				p[cnt].s[len++] = c;
			c = getchar();
		}
		if(len){
			p[cnt].s[len] = '\0';
			p[cnt].len = len;
			cnt++;	
		}
		qsort(p,cnt,sizeof(p[0]),cmp);
		for(int i = 0;i < cnt;i++)
			printf("%s%c",p[i].s,(i == cnt-1 ? '\n' : ' '));
		cnt = 0;
		len = 0;
		c = getchar();
		free(p);
	}
	return 0;
}
int cmp(const void* a,const void* b){
	str* aa = (str*)a;
	str* bb = (str*)b;
	int len = aa->len < bb->len ? aa->len : bb->len;
	for(int i = 0;i < len;i++){
		if(aa->s[i] != bb->s[i]){
			return tab[aa->s[i]] - tab[bb->s[i]];
		}
	}
	return aa->len - bb->len;
}
	 