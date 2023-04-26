#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct data{
	int d;
	char s[50];
}a[101];
int cmp(const void*a,const void*b)
{
	struct data s1=*(struct data*)a;
	struct data s2=*(struct data*)b;
	if(s1.d>=0&&s2.d>=0)
	{
		if(s1.d!=s2.d)
		{
			return s1.d-s2.d;
		}
		else{
			return strcmp(s1.s,s2.s);
		}
	}
	if(s1.d==-1&&s2.d==-1)
	{
		return strcmp(s1.s,s2.s);
	}
	else{
		return s1.d-s2.d;
	}
}
int main()
{
	int n=0;
	int i=0,j=0,k=0;
	while(scanf("%s",a[i].s)!=EOF)
	{
		int temp=0,flg=0; 
		for(k=0;k<strlen(a[i].s);k++)
		{
			while(a[i].s[k]>='0'&&a[i].s[k]<='9')
			{
				flg=1;
				temp*=10;
				temp+=(a[i].s[k]-'0');
				k++;
			}
		}
		if(flg==1)
		{
			a[i].d=temp;
		}
		else{
			a[i].d=-1;
		}
		//printf("temp:%d\n",a[i].d);
		n++;
		i++;
	}
	qsort(a,n,sizeof(a[0]),cmp);
	for(i=0;i<n;i++)
	{
		printf("%s ",a[i].s);
	}
	
}