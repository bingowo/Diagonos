#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int cmp(const void* p1,const void* p2){
	char a = *((char*)p1);
	char b = *((char*)p2);
	if(!isalpha(a))
		return 1;
	if(!isalpha(b))
		return -1;
	return a-b;
}
int main()
{
	int T;
	scanf("%d",&T);
	getchar();
	char sentence[201];	
	char stc[201];
	int a=0;
	for(int k=0;k<T;k++){
		gets(sentence);
		strcpy(stc,sentence);
		qsort(stc,strlen(stc),sizeof(char),cmp);
		for(int i=0;i<strlen(sentence);i++){
			if(isalpha(sentence[i])){
				sentence[i]=stc[a++];
			}
		}
		printf("case #%d:\n",k);
		for(int i=0;i<strlen(sentence);i++){
			printf("%c",sentence[i]);
		}
		//puts(sentence);
		printf("\n");
	}

	//500 DONGCHUAN ROAD EAST 200241
	return 0;
}