#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char ch;
	double f;
}Alph;

int cmp(const void* p1,const void* p2){
	Alph *a = (Alph*)p1;
	Alph *b = (Alph*)p2;
	if(a->f>b->f)
		return -1;
	if(a->f<b->f)
		return 1;
	return b->ch-a->ch;
}

int main()
{
	int T;
	scanf("%d",&T);
	//Alph alph[26];
	
	for(int i=0;i<T;i++){
		char s[110];
        double fps[26]={0.0};
		for(int j=0;j<26;j++){
			//alph[j].ch = j+'A';
			scanf("%lf",&fps[j]);
 		}
 		scanf("%s",s);
 		Alph str[110];
 		for(int j=0;j<strlen(s);j++){
 			str[j].ch = s[j];
 			if(s[j]>='a'&&s[j]<='z')
 				str[j].f = fps[s[j]-'a'];
 			if(s[j]>='A'&&s[j]<='Z')
 				str[j].f = fps[s[j]-'A'];
		}
		qsort(str,strlen(s),sizeof(Alph),cmp);
		printf("case #%d:\n",i);
		for(int j=0;j<strlen(s);j++){
			printf("%c",str[j].ch);
		}
		printf("\n");
	}
	return 0;
}