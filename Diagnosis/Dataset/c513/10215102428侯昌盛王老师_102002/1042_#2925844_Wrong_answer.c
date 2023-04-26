#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct m{
	char k[17];
};
int cmp(const void*a,const void*b)
{
	char p,q;
	p=*(char*)a;q=*(char*)b;
	if(p>q) return 1;
	else return -1;
}

int cmp2(const void*a,const void*b)
{
	struct m *p,*q;
	p=(struct m*)a;
	q=(struct m*)b;
	if((p->k)>(q->k)) return 1;
	else if((p->k)<(q->k))  return -1;
	while((p->k)==(q->k))
	{
		p++;q++;
		if((p->k)>(q->k)) return 1;
		else if((p->k)<(q->k))  return -1;
	}
		
	
}

int main()
{
	int t,i=0;
	scanf("%d",&t);
	for(i;i<t;i++)
	{
		char s[17],s1[17]={0};
		int j,len;
		scanf("%s",s);
		s1[0]=s[0];
		len=strlen(s);
		//printf("%d",len);
		for(j=1;j<len;j++)
		{
			int len1,k=0,n=0;
			len1=strlen(s1);
		//	printf("%c\n",s1[0]);
			while(k<len1)
			{
				if(s1[k]!=s[j]) n++;
				k++;
			}
			if(n==k) s1[k]=s[j];
			
		}
		int n=strlen(s1);
		qsort(s1,n,sizeof(s1[0]),cmp);
		int d,e,u=0,h=0;
		struct m ss[17];
		for(d=0;d<(1<<n);d++)
		{
			for(e=0;e<n;e++)
			{
				if(d&(1<<e)) ss[u].k[h++]=s1[e];
			}
			u++;
		
		}
		qsort(ss,u,sizeof(ss[0]),cmp2);
		for(i=0;i<u;i++)
		{
			printf("%s\n",ss[i].k);
		}
		
		
	}
		
	
	return 0;
}