#include<stdio.h>
#include<string.h>

int f(char *ss,int *len)
{
	int del=0,fir=0,c=1;
	while(fir<*len)
	{
		while(fir+c<=*len && ss[fir] == ss[fir+c])
			c++;
		if(c>1)
		{
			int i=fir+c;
			while(i <= *len)
				ss[i-c]=ss[i],i++;
			*len-=c;
			del+=c,c=1;
		}else
			fir++;
	}
	return del;
}
int del_repeat(char s[],char x,int pos,int len)
{
	int del=0;
	char ss[105]={0};
	ss[pos]=x;
	for(int i=0;i<len;i++)
	{
		if(i<pos)
			ss[i]=s[i];
		else
			ss[i+1] = s[i];
	}
	int m=0,n=len;
	while(m=f(ss,&n),m > 0 )
		del += m;
	return del + m;
}

int main()
{
	int t;
	scanf("%d",&t);
	char table[4]="ABC";
	for(int i=0;i<t;i++)
	{
		char s[102]={0};
		scanf("%s",s);
		int len =strlen(s);
		int maxdel=0,temp=0;
		for(int i=0;i<3;i++)
		{
			char x = table[i];
			for(int i=1;i<len;i++)
			{
				temp = del_repeat(s,x,i,len);
				if(temp >= maxdel)
					maxdel = temp;
			}
		}
		printf("case #%d:\n%d\n",i,maxdel);
	}
	return 0;
}