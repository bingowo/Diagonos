#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int cmp(const void*a,const void*b)
{
	return strcmp((char*)a,(char*)b);
}
int main()
{  int k,T;
	scanf("%d\n",&T);
	for(k=0;k<T;k++)
	{  	char s[600]={'\0'};
		char word[502][502]={'\0'};
		char wo[502][502]={'\0'};
		gets(s);
		int i,l=strlen(s),n=0,d=0,cnt=1;
		for(i=0;s[i]==' '||s[i]==','||s[i]=='.'||s[i]=='?'||s[i]=='!';);
		while(i<l)
		{	int p,j=0,flag=0;
			for(p=i;p<l&&s[p]!=' '&&s[p]!=','&&s[p]!='.'&&s[p]!='?'&&s[p]!='!';p++) 
							flag=1,	word[n][j++]=s[p];
			if(flag==1) n++;
			for(i=p;s[i]==' '||s[i]==','||s[i]=='.'||s[i]=='?'||s[i]=='!';i++);
		}
		strcpy(wo[0],word[0]);
		for(i=1;i<n;i++)
		{for(d=0;d<=i;d++)
			if(!strcmp(word[d],word[i])) continue; 
			strcpy(wo[cnt++],word[i]); 
		}
		qsort(wo,cnt,sizeof(wo[0]),cmp);
	    printf("case #%d:\n",k);
		for(i=0;i<cnt-1;i++) printf("%s ",wo[i]);
		printf("%s\n",wo[i]);
	}
	return 0;
}