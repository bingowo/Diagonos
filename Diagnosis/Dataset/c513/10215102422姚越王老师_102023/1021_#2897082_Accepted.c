#include<stdio.h>
#include<stdlib.h>
int array[128]={0};
int cmp(const void* a,const void* b)
{
	char *p1=(char*)a,*p2=(char*)b;
	int i=0;
	while(p1[i]==p2[i]+32||p2[i]==p1[i]+32||p1[i]==p2[i])i++;
	if(i==strlen(p1))return -1;
	else if(i==strlen(p2))return 1;
	else return array[p1[i]]-array[p2[i]];
		
	
}
int main()
{
	char s[26];
	int i;
	while(~scanf("%s\n",s))
	{
		for(i=0;s[i];i++){array[s[i]]=i;array[s[i]+32]=i;}
		char str[2200];
		char b[100][21];
		int count=1,j=0,k=0;
		gets(str);
		char *p=str;
		while(*p++)if(*p==' ')count++;
		for(i=0;i<count;i++)
		{
			for(j;str[j]!=' '&&str[j];j++)
			{
				b[i][k++]=str[j];
			}
			b[i][k]=0;
			k=0;j++;
		}
		//for(i=0;i<128;i++)printf("%c=%d ",i,array[i]);
		//printf("\n");
		qsort(b,count,sizeof(b[0]),cmp);
		for(i=0;i<count-1;i++)printf("%s ",b[i]);
		printf("%s\n",b[i]);
	}
}