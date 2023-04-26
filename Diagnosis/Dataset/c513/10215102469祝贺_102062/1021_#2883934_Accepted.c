#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char dict[27],table[256];
int cmp(const void* a,const void* b){
	char *s1=(char*)a,*s2=(char*)b;
	//printf("%s  %s\n",s1,s2);
	int p=0;
	while(s1[p]!=0 && s2[p]!=0){
		if(table[toupper(s1[p])]!=table[toupper(s2[p])]){
			return table[toupper(s1[p])]-table[toupper(s2[p])];
		}
		p++;
	}
	if(s1[p]==0)return -1;
	else return 1;
}
int main()
{
	while(fgets(dict,27,stdin)!=NULL){
		char words[100][25];int sp=0;

		for(int i=0;i<26;i++){
			table[dict[i]]=i;
		}
		while(1){
            scanf("%s",words[sp++]);
            if(getchar()=='\n')break;
		}
		qsort(words,sp,sizeof(words[0]),cmp);
		for(int i=0;i<sp;i++){
		printf("%s ",words[i]);
		}
		printf("\n");
	}


	return 0;
}
