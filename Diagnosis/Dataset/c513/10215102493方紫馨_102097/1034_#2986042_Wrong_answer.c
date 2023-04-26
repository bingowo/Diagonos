#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
float alph[26];

int cmp(const void*p1,const void*p2){
	char a = *((char*)p1);
	char b = *((char*)p2);
	if(toupper(a)==toupper(b))
		return b-a;
	float d = alph[toupper(b)-'A'] - alph[toupper(a)-'A'];
	if(d>0)
		return 1;
	else 
		return -1;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int k=0;k<T;k++){
		for(int i=0;i<26;i++){
			scanf("%f",&alph[i]);
		}
		char s[101];
		scanf("%s",s);
		qsort(s,strlen(s),sizeof(s[0]),cmp);
		printf("case #%d:\n",k);
		printf("%s\n",s);
	}
	
	
	return 0;
}