#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int cmp(const void*a,const void*b)
{
	int x=*(int*)a;int y=*(int*)b;
	if(x<y)return -1;return 1;
}
int main()
{
	char ss[25];int s[25];
	int ct=0,T;scanf("%d",&T);
	while(T--)
	{
		scanf("%s",ss);
		int n=strlen(ss),pos1,pos2,last=10,sig=0;
		for(int i=0;i<n;i++)s[i]=ss[i]-'0';
		for(int i=n-2;i>=0;i--)
		{
			for(int j=i+1;j<n;j++)
			{
				if(s[j]>s[i])
				{
					sig=1;
					if(s[j]<last)
					{
						pos1=i;pos2=j;last=s[j];
					}
				}
			}
			if(sig)break;
		}
		int c=s[pos1];s[pos1]=s[pos2];s[pos2]=c;
		qsort(s+pos1+1,n-pos1,sizeof(int),cmp);
		printf("case #%d:\n",ct++);
		for(int i=0;i<n;i++)printf("%d",s[i]);printf("\n");
	}
	return 0;
}