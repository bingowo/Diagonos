#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>

typedef struct{
	int r;//行 
	int c;//列 
	char ch; 
}n_n;
int cmp(const void*a,const void*b)
{
	n_n*p1=(n_n*)a;n_n*p2=(n_n*)b;
	if(p1->r<p2->r) return -1;
	else if(p1->r>p2->r) return 1;
	else
	{
		if(p1->c>p2->c) return 1;
		else return -1;
	}
}

int main()
{
	char ind[105];
	while(scanf("%s",ind)!=EOF)
	{
		int l=strlen(ind);
		if(l==1) {printf("%s\n",ind);continue;}
		n_n *p=(n_n*)malloc(l*sizeof(n_n));
		p[0].ch=ind[0];
		p[0].r=0;p[0].c=0;
		for(int i=1;i<l;i++)
		{
			p[i].ch=ind[i];
			p[i].c=p[i-1].c+1;
			if(p[i].ch>p[i-1].ch) p[i].r=p[i-1].r+1;
			else if(p[i].ch<p[i-1].ch) p[i].r=p[i-1].r-1;
			else p[i].r=p[i-1].r;
		}
		qsort(p,l,sizeof(p[0]),cmp);
	//	for(int i=0;i<l;i++) printf("%d %d %c\n",p[i].r,p[i].c,p[i].ch);
		int len=p[l-1].r-p[0].r+1;
	//	printf("len:%d\n",len);
		char ans[200][210];
		for(int i=0;i<200;i++) for(int j=0;j<210;j++) ans[i][j]=' ';
		int k=0,b=0;
		ans[k][p[b].c]=p[b].ch;//printf("%c %d %d\n",ans[k][p[b].c],k,p[b].c);
		b++;
		
		while(k<len)
		{
			if(p[b].r==p[b-1].r) ans[k][p[b].c]=p[b].ch,b++;//printf("%c %d %d\n",ans[k][p[b].c],k,p[b].c),b++;
			else
			{
				ans[k][p[b-1].c+1]='\0';//printf("%s\n",ans[k]);
				k++;
				if(k<len) ans[k][p[b].c]=p[b].ch;//printf("%c %d %d\n",ans[k][p[b].c],k,p[b].c);
				b++;
			}
		}
		
		for(int i=k-1;i>=0;i--) printf("%s\n",ans[i]);
		
	}
	return 0;
}