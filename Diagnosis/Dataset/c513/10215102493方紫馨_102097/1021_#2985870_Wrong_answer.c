#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int alph[128];
typedef struct {
	char ch[25];
}W;
W word[100];
int cmp(const void*p1,const void*p2){
	W* a = (W*)p1;
	W* b = (W*)p2;
	int k=0;
	while(toupper(a->ch[k])==toupper(b->ch[k]))
		k++;
	return alph[toupper(a->ch[k])]- alph[toupper(b->ch[k])];
}

int main()
{	
	char s[27];
	while(scanf("%s",s)!=EOF){
		for(int i=0;i<26;i++){
			alph[s[i]] = i;
		}
		int idx=0;
		while(1){
			scanf("%s",word[idx].ch);
			idx++;
			if(getchar()=='\n')
				break;
		}
		qsort(word,idx,sizeof(word[0]),cmp);
		for(int i=0;i<idx-1;i++){
			printf("%s ",word[i].ch);
		}
		printf("%s\n",word[idx-1].ch);
	}
	return 0;
}