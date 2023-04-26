#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
	char *A=(char *)a;
	char *B=(char *)b;
	if(*A>='A'&&*A<='Z')
	{
		if(*B>='A'&&*B<='Z') return *A-*B;
		else if(*A-'A'!=*B-'a') return *A-'A'-*B+'a';
		else return -1;
	}
	else if(*B>='A'&&*B<='Z')
	{
		if(*A-'a'!=*B-'A') return *A-'A'-*B+'a';
		else return 1;
	}
	else
	{
		return *A-*B;
	}
}
int main()
{
    int t;
    char s[20],x[20];
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
		scanf("%s",s);
		char *q=s;
		qsort(q,strlen(s),sizeof(s[0]),cmp);
		int k=0;x[k]=s[0];
		for(int j=1;s[j]!='\0';j++)
		{
			if(s[j]!=x[k])
			{
				k++;x[k]=s[j];
			}
		}
		printf("case #%d:\n",i);
		for(int j=0;j<=k;j++)
		{
			printf("%c\n",x[j]);
			for(int o=j+1;o<=k;o++)
			{
				for(int p=j;p<=o;p++)
				{
					printf("%c",x[p]);
				}
				printf("\n");
			}
		}
		
	}
}

