#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

double freq[26];

int cmp(const void *ac,const void *bc)
{
	char a=*(char*)ac,b=*(char*)bc;
	int alower=0,blower=0;
	if(a>='a'){alower++;a=a-32;}
	if(b>='a'){blower++;b=b-32;}
	if(freq[a-'A']>freq[b-'A'])return -1;
	if(freq[a-'A']<freq[b-'A'])return 1;
	if(a<b)return -1;
	if(a>b)return 1;
	if(alower==1&&blower==0)return -1;
	if(alower==0&&blower==1)return 1;
	
	
	return 0;
}

int main()
{
	char input[101];
	int c,cases;
	int i,j,p;
	
	
	scanf("%d",&cases);
	for(c=0;c<cases;c++)
	{
		for(i=0;i<26;i++)scanf("%lf",&freq[i]);
		scanf("%s",&input);
		qsort(input,strlen(input),sizeof(char),cmp);
		printf("case #%d:\n",c);
		printf("%s",input);
		if(c!=cases-1)putchar('\n');
	}
	
	
	
	return 0;
}