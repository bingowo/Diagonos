#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLINE 1000001
typedef struct{char user[MAXLINE];char mac[MAXLINE];} mail;
int cmp(const void* a,const void* b)
{
	mail *ax=(mail*)a,*bx=(mail*)b;
	if(strcmp(ax->mac,bx->mac)!=0)return strcmp(ax->mac,bx->mac);
	else return -strcmp(ax->user,bx->user);
}
int main()
{
	int n;scanf("%d",&n);
	mail a[n];
	for(int cnt=0;cnt<n;cnt++) 
	{
		char s[MAXLINE];
		scanf("%s",s);
		int i;
		for(i=0;s[i];i++)if(s[i]=='@')break;
		int k;
		for(k=0;k<i;k++)a[cnt].user[k]=s[k];
		a[cnt].user[k]=0;
		int j=0;i++;
		while(s[i])a[cnt].mac[j++]=s[i++];
		a[cnt].mac[j]=0;
	}
	qsort(a,n,sizeof(a[0]),cmp);
	for(int i=0;i<n;i++)
	{
		printf("%s@%s\n",a[i].user,a[i].mac);
	}
	return 0;
}