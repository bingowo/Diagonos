#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void readpoly(char *p,int *co)
{
	while(*p)
	{
		int sign=1,c=0,d=0;
		if(*p=='+')p++;
		else if(*p=='-')sign=-1,p++;
		while(isdigit(*p)){c=c*10+*p-'0';p++;}
		if(*p!='x'){co[0]=c*sign;return;}else p++;
		if(c==0)c=1;
		if(*p=='^')p++;
		while(isdigit(*p)){d=d*10+*p-'0';p++;}
		if(d==0)d=1;
		co[d]=c*sign;
	}
}
void multi(int *ax,int *bx,int *cx);
int main()
{
	char s[110],a[110],b[110];
	int i,j,k;
	while((gets(s))!=0)
	{
		for(i=0;i<strlen(s);i++)if(s[i]==' ')break;
		for(j=0;j<i;j++)a[j]=s[j];
		a[j]=0;
		k=0;
		for(j=i+1;j<strlen(s);j++)b[k++]=s[j];
		b[k]=0;
		//printf("%s %s\n",a,b);
		int ax[50]={0},bx[50]={0};
		readpoly(a,ax);
		readpoly(b,bx);//至此，我们将a,b各项的系数存到了数组里，数组的索引就是a和b的次数
		int cx[100]={0};
		multi(ax,bx,cx);
		for(j=99;j>=0;j--)
		{
			if(cx[j])printf("%d ",cx[j]);
		}
	}
	return 0;
}
void multi(int *ax,int *bx,int *cx)
{
	int i,j,lena,lenb;
	for(i=0;i<49;i++)
	{
		for(j=0;j<49;j++)
		{
			cx[i+j]+=ax[i]*bx[j];
		}
	}
}