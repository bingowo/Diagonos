#include <stdio.h>
#include <string.h>
int number(char *a)
{
	int n,len;
	len=strlen(a);
	int i=0,j;
	n=len;
	for(i;i<len-1;i++)
	{
		for(j=i+1;j<len;j++)
		{
			if(a[i]==a[j]) n--;
		}
	}
	return n;
}

int cmp(const void *a,const void *b)
{
	char *q,*p;
	int num1,num2,i=0;
	q=(char*)a;p=(char*)b;
	num1=number(q);num2=number(p);
	if(num1!=num2) return num2-num1;
	else{
		while(1)
		{
			if(q[i]!=p[i]) return q[i]-p[i];
			else i++;
		}
	}
	
}
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int n,j,count=0;
		scanf("%d",&n);
		char s[200][100];
		for(j=0;j<n;j++)
		{
			scanf("%s",s[count++]);
		}
		qsort(s,count,sizeof(s[0]),cmp);
		printf("case #%d:\n",i);
		int k=0;
		for(k;k<count;k++) printf("%s\n",s[k]);
		
	}
	return 0;
}