#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h> 
char alph[128];

int cmp(const void* p1,const void* p2){
	char * a = (char*)p1;
	char * b = (char*)p2;
	int i=0;
	while(toupper(a[i])==toupper(b[i])){
		i++;
		if(i==strlen(a))
			return -1;
		if(i==strlen(b))
			return 1;			
	}
	return alph[a[i]]-alph[b[i]];
}

int main()
{
	char s[30];
	while(scanf("%s",s)!=EOF){
		for(int i=0;i<26;i++){
			alph[s[i]]=i+1;
			alph[s[i]-'A'+'a']=i+1;
		}
		char word[101][10];
		int a=0;
		while(1){
			scanf("%s",word[a]);
			a++;			
			if(getchar()=='\n')
				break;
		}
		qsort(word,a,sizeof(word[0]),cmp);
		for(int i=0;i<a-1;i++){
			printf("%s ",word[i]);
		}
		printf("%s\n",word[a-1]);
	}
	
	
	
	return 0;
}