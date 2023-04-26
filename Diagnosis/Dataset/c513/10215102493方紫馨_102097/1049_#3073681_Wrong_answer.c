#include<stdio.h>
#include<string.h>
#include<stdlib.h> 

int cmp(const void* p1,const void* p2){
	char* a = (char*)p1;
	char* b = (char*)p2;
	return strcmp(a,b);
}

int main()
{
	int T;
	scanf("%d",&T);
	getchar();
	for(int k=0;k<T;k++){
		char s[501];
		char word[300][15];
		gets(s);
		int a=0,b=0;
		for(int i=0;i<strlen(s)+1;i++){
			if(s[i]==' '||s[i]==','||s[i]=='.'||s[i]=='?'||s[i]=='!'||s[i]=='\0'){
				if(b==0){
					continue;
				}
				word[a][b]='\0';
				a++;
				b=0;
				continue;
			}
			word[a][b++]=s[i];
		}
		qsort(word,a,sizeof(word[0]),cmp);
		printf("case #%d:\n",k);
		printf("%s ",word[0]);
		for(int i=1;i<a-1;i++){
			if(strcmp(word[i-1],word[i])!=0){
				printf("%s ",word[i]);
			}			
		}
		if(strcmp(word[a-1],word[a-2])!=0){
				printf("%s",word[a-1]);
			}	
		printf("\n");		
	}	
	return 0;
}