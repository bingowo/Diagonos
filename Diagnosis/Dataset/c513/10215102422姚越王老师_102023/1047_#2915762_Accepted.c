#include<stdio.h>
#include<string.h>
typedef struct{char c;int start;int n;} word;//字符，字符开始位置，字符个数 
int main()
{
	int T,i,j,k,len,cnt;scanf("%d\n",&T);
	char s[510];
	for(i=0;i<T;i++)
	{
		gets(s);cnt=1;
		len=strlen(s);
		for(j=0;j<len-1;j++)
		{
			if(s[j+1]!=s[j])cnt++;
		}
		word a[cnt];//a数组用于记录每个不同的字符 
		k=0;
		a[k].c=s[0];
		a[k++].start=0;
		for(j=0;j<len-1;j++)if(s[j+1]!=s[j]){a[k].start=j+1;a[k++].c=s[j+1];}
		//初始化每个字符和字符的起始位置 
		for(j=0;j<cnt-1;j++)a[j].n=a[j+1].start-a[j].start;
		a[j].n=len-a[j].start;
		printf("case #%d:\n",i);
		for(j=0;j<cnt;j++)
		{
			while(a[j].n>255)
			{
				printf("%d%c",255,a[j].c);
				a[j].n-=255;
			}
			printf("%d%c",a[j].n,a[j].c);
		}
		printf("\n");
	}
	return 0;
}