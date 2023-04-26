#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int table[256],num,cnt;
char s[17],chr[17];
typedef struct{
	char S[17];
}ANS;
ANS ans[65536];
int cmp1(const void* a,const void* b)
{
	char x=*(char*)a;char y=*(char*)b;
	if(x>='a'&&x<='z'&&y>='A'&&y<='Z')return  1;
	if(x>='A'&&x<='Z'&&y>='a'&&y<='z')return -1;
	if(x<y)return -1;
	return 1;
}
int cmp2(const void* a,const void* b)
{
	ANS x=*(ANS*)a;ANS y=*(ANS*)b;
	return strcmp(x.S,y.S);
}
void output(int pos,int k)
{
	if(pos>num)
	{
		if(k==0)return;
		s[k]=0;
		strcpy(ans[cnt++].S,s);
		return;
	}
	output(pos+1,k);
	s[k]=chr[pos];
	output(pos+1,k+1);
}
int main()
{
	int ct=0,T;scanf("%d",&T);
	while(T--)
	{
		num=cnt=0;
		memset(table,0,sizeof(table));
		scanf("%s",s);int n=strlen(s);
		for(int i=0;i<n;i++)
		{
			if(table[s[i]]==0)chr[++num]=s[i];
			table[s[i]]=1;
		}
		qsort(chr+1,num,sizeof(char),cmp1);
		output(1,0);
		qsort(ans,cnt,sizeof(ANS),cmp2);
		printf("case #%d:\n",ct++);
		for(int i=0;i<cnt;i++)printf("%s\n",ans[i].S);
	}
}