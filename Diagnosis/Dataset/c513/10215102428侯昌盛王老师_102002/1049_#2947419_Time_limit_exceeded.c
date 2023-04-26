#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{
	char *p,*q;
	p=(char*)a;q=(char*)b;
	if(*p>*q) return 1;
	else if(*p<*q) return -1;
	while(*p==*q)
	{
		p++;q++;
		if(*p>*q) return 1;
		else if(*p<*q) return -1;
	}
}
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		char s0[501],s1[501][50],c,h=0;
		while((c=getchar())!='\n');
		gets(s0);
		//printf("%s\n",s0);
		int j=0,len=strlen(s0),h1=0,h2=0;
		while(j<len)
		{
			if(s0[j]==' '||s0[j]==','||s0[j]=='.'||s0[j]=='!'||s0[j]=='?'){
				h1++;
				h2=0;
			}
			else s1[h1][h2++]=s0[j];
			j++;
			
		}
		//printf("%s",s1[1]);
		qsort(s1,h1,sizeof(s1[0]),cmp);
		char s2[501][50];
		int n=1,k=0;
		strcpy(s2[0],s1[0]);
		while(n<len)
		{
			if(strcmp(s2[k],s1[n])){
				strcpy(s2[k+1],s1[n]);
				k++;
			}
			n++;
		
		}
		printf("case #%d:\n",i);
		int h3=0;
		for(h3;h3<k;h3++) printf("%s ",s2[h3]);
		printf("\n");
		
	}
	return 0;
}