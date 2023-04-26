#include <stdio.h>
#include <ctype.h>
void multiply(char*s1,char*s2,int*co);
void readpoly(char*p,int*co);
int main()
{
	char s1[100],s2[100];
	scanf("%s %s",s1,s2);
	int co[100]={0},out[100],n=0,i;
	multiply(s1,s2,co);
	for(i=0;i<100;i++) if(co[i]) out[n++]=co[i];
	for(i=n-1;i>=0;i--)
	{
		printf("%d",out[i]);
		if(i>0) printf(" ");
		else printf("\n");
	}
	return 0;
}

void multiply(char *s1,char *s2,int*co)
{
	int co1[100]={0},co2[100]={0},i,j;
	readpoly(s1,co1);readpoly(s2,co2);
	for(i=0;i<50;i++)
		for(j=0;j<50;j++) co[i+j]+=co1[i]*co2[j];
}

void readpoly(char*p,int*co)
{
	while(*p)
	{
		int sign=1,c=0,d=0;
		if(*p=='+') p++;
		else if(*p=='-'){sign=-1;p++;}
		while(isdigit(*p)){c=c*10+*p-'0';p++;}
		if(*p!='x'){co[0]=c*sign;return;}
		else p++;
		if(c==0) c=1;
		if(*p=='^') p++;
		while(isdigit(*p)){d=d*10+*p-'0';p++;}
		if(d==0) d=1;
		co[d]=c*sign;
	}
}