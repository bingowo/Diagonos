#include<stdio.h>
#include<string.h>

void delet(char*s1,const char*s2)
{
	char*p=s1,*q,*c,d[100];
	unsigned long n=strlen(s2);
	while(1)
	{
		q=strstr(p,s2);
		if(q==NULL)
			break;
		c=q+n;
		*q='\0';
		strcpy(d,c);
		p=strcat(p,d);	
	}
}

int main(){
	char s[10][101];
	int i,n;
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		gets(s[i]);
	}
	char sa[]="a\0",sb[]="an\0",sc[]="the\0",sd[]="of\0",se[]="for\0";
	for(i=0;i<n;i++)
	{
		delet(s[i],sa);delet(s[i],sb);delet(s[i],sc);delet(s[i],sd);delet(s[i],se);
	}
	for(i=0;i<n;i++)
	{	int m=1,k;
		for(k=0;s[i][k]!='\0';k++)
		{
			if((int)s[i][k]==32)
			{
				m++;
				k++;
			}
		}
		printf("case #%d:\n%d\n",i,m);

	}
}