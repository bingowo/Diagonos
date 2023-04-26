#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void comb(char* s,char* char_comb)
{
	if(*s)
	{
		char left[17]={0};
		sprintf(left,"%s%c",char_comb,s[0]);
		printf("%s\n",left);
		comb(s+1,left);
		comb(s+1,char_comb);
	}
}

int cmp(const void *a,const void* b)
{
	return *(char*)a-*(char*)b;
}

void solve(int T)
{
	char s[17];
	scanf("%s",s);
	int i;
	int list[128];
	char letter[17];
	for (i=0;i<128;i++){
		list[i]=-1;
	}
	int len=strlen(s);
	int k=0;
	for (i=0;i<len;i++){
		int a=s[i];
		if(list[a]==-1){
			list[a]=1;
			letter[k]=a;
			k++;
		}
	}
	letter[k]='\0';
	qsort(letter,k,sizeof(char),cmp);
	char t[17]={0};
	comb(letter,t);
}

int main()
{
	int T;
	scanf("%d",&T);
	for (int i=0;i<T;i++){
		printf("case #%d:\n",i);
		solve(i);
	}
	return 0;
 } 