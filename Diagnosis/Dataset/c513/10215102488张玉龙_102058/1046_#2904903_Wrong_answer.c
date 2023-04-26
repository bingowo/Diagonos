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
	char sa1[]="a\0",sb1[]="an\0",sc1[]="the\0",sd1[]="of\0",se1[]="for\0",sf1[]="and\0";
	char sa2[]="A\0",sb2[]="AN\0",sc2[]="THE\0",sd2[]="OF\0",se2[]="FOR\0",sf2[]="AND\0";
	for(i=0;i<n;i++)
	{
		delet(s[i],sf1);delet(s[i],sb1);delet(s[i],sa1);delet(s[i],sc1);delet(s[i],sd1);delet(s[i],se1);
		delet(s[i],sf2);delet(s[i],sb2);delet(s[i],sa2);delet(s[i],sc2);delet(s[i],sd2);delet(s[i],se2);
	}
	for(i=0;i<n;i++)
	{	int m=1,k;
		for(k=0;s[i][k]!='\0';k++)
		{
			if((int)s[i][k]==32)
			{
				m++;
				while((int)s[i][k+1]==32)
				k++;
			}
		}
		printf("case #%d:\n%d\n",i,m);

	}
}