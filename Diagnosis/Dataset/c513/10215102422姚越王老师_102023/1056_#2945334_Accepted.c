#include<stdio.h>
#include<malloc.h>
#include<string.h>
int main()
{
	int n,i,j,k,l,maxlen=-1,len,flag,dl;scanf("%d",&n);char** a=(char**)malloc(sizeof(char*)*n);char s[5001],s2[5001],tmp[15];
	for(i=0;i<n;++i)
	{
		scanf("%s",s);char *p=(char*)malloc(sizeof(char)*strlen(s));
		len=strlen(s);
		if(len>maxlen)maxlen=len;
		strcpy(p,s); a[i]=p;
		//printf("%d %d %d\n",strlen(s),i,maxlen);
	}
	scanf("%s",s);
	while(strlen(s))
	{
		//printf("%s\n",s);
		l=maxlen;flag=0;
		while(l)	
		{
			for(i=0;i<l;i++)tmp[i]=s[i]; tmp[i]=0;
			for(i=0;i<n;i++)if(!(strcmp(tmp,a[i])))
			{
				printf("%s ",tmp);
				flag=1;
				break;
			}
			if(flag)break;
			else l--;
		}
		if(flag)
		{
			dl=strlen(a[i]);
			for(j=dl,k=0;s[j];j++,k++)s2[k]=s[j]; s2[k]=0; strcpy(s,s2);
		}
		else
		{
			printf("%c ",s[0]);
			for(j=0;j<strlen(s)-1;j++)s[j]=s[j+1]; s[j]=0;
		}
	}
	for(i=0;i<n;i++)free(a[i]); free(a);	
	return 0;
}