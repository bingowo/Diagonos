#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
	char *p,*q;
	p=(char*)a;q=(char*)b;
	if(*p>*q) return 1;
	else return -1;
}

int cmp2(const void*a,const void*b)
{
	char *p,*q;
	p=(char*)a;
	q=(char*)b;
	if(*p!=*q){
		if(*p>*q) return 1;
		else return -1;
	}
	while(*p==*q)
	{
		p++;q++;
		if(*p>*q) return 1;
		else if(*p<*q) return -1;
	}
	
}

int main()
{
	int t,i=0;
	scanf("%d",&t);
	for(i;i<t;i++)
	{
		char s[17],s1[17];
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
		int d,e,u=0,h=0,w1=0;
		char ss[17][17];
		for(d=0;d<(1<<n);d++)
		{
			for(e=0;e<n;e++)
			{
				if(d&(1<<e)) {
					ss[u][h++]=s1[e];
					w1++;
				//	printf("%c",ss[u][h-1]);
				}
				
			}
			if(w1!=0) u++;
			w1=0;
			h=0;
			printf("\n");
		//	printf("%s",ss[0]);
		
		}
		
		int kk=0;
	

		qsort(ss,u,sizeof(ss[0]),cmp2);
		int www=0;
		for(www=0;www<u;www++)
		{
			printf("%s\n",ss[www]);
		}
		
		
	}
		
	
	return 0;
}