#include <stdio.h>
#include <string.h>

int Fromleft(char*s0,char*s)
{
	char*p=strstr(s,s0);
	return p==0?-1:p-s;
}

int Fromright(char*s0,char*s)
{
	char *p=s,*p1=0;
	while((p1=strstr(p,s0))!=0) p=p1+1;
	return p-s-1;
}

int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		char s1[81],s2[81],s3[81];
		scanf("%s",s1);
		scanf("%s",s2);
		scanf("%s",s3);
		int len1,len2;
		len1=strlen(s1);
		len2=strlen(s2);
		int max,ls1,rs2,n1;
		ls1=Fromleft(s1,s3);
		rs2=Fromright(s2,s3);
		n1=rs2-(ls1+len1-1)-1;
		int rs1,ls2,n2;
		ls2=Fromleft(s2,s3);
		rs1=Fromright(s1,s3);
		n2=rs1-(ls2+len2-1)-1;
		if(n1>n2) max=n1;
		else max=n2;
		printf("case #%d:\n",i);
		printf("%d\n",max);
		
		
	}
	return 0;
}