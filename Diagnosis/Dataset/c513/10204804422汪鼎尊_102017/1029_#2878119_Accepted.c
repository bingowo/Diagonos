#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int cmp(const void *ac,const void *bc)
{
	char a=*(char*)ac,b=*(char*)bc;
	if(a==b)return 0;
	if(a>b)return 1;
	return -1;
}

int main()
{
	char input[201];
	char cmparr[201];
	int c,cases;
	int i,j,p;
	
	scanf("%d",&cases);getchar();
	for(c=0;c<cases;c++)
	{
		p=0;j=0;
		gets(input);
		for(i=0;i<strlen(input);i++)if(input[i]>='A'&&input[i]<='Z')cmparr[j++]=input[i];
		qsort(cmparr,j,sizeof(char),cmp);
		
		
		printf("case #%d:\n",c);
		j=0;
		for(i=0;input[i]!='\0';i++)putchar((input[i]>='A'&&input[i]<='Z')?cmparr[j++]:input[i]);
		if(c!=cases-1)putchar('\n');
	}
	
	
	
	return 0;
}