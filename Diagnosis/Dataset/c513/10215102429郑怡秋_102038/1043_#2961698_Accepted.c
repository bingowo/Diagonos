#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int del(int j,char a[])
{
	char b[120];
	int l=strlen(a);
	
	if(j<l)
	{
		for(int i=0;i<=j;i++) b[i]=a[i];
		b[j+1]=a[j];
		for(int i=j+2;i<=l;i++) b[i]=a[i-1];
		b[l+1]='\0';
		l+=1;
	}
	else strcpy(b,a);
	//printf("j:%d l:%d b:%s\n",j,l,b);
	int ans=0;
	char c[120];
	strcpy(c,b);
	for(int i=0;i<l-1;i++)
	{
		if(c[i]==c[i+1]) 
		{
			if(b[i]=='0') ans+=1;
			else ans+=2;
			b[i]='0';b[i+1]='0';
		}
	}
	int index=0;
	for(int i=0;i<l;i++)
	{
		if(b[i]!='0') a[index++]=b[i];
	}
	a[index]='\0';
//	printf("an:%d\n",ans);
	if(ans==1) return 0;
	else return ans;
}

int main()
{
	int t;
	scanf("%d",&t);
	char s[120];
	for(int i=0;i<t;i++)
	{
		scanf("%s",s);
		int ans=0,anc=0;
		char a[120];
		
		int l=strlen(s);
		for(int j=0;j<l;j++)
		{	ans=0;
			strcpy(a,s);
			int h=j,an=1;//printf("al:%d\n",strlen(a));
			while(an!=0) an=del(h,a),ans+=an,h=l;//printf("an:%d\n",an);
			
			if(ans>anc) anc=ans;
		}
		printf("case #%d:\n%d\n",i,anc);
	}
	return 0;
 } 