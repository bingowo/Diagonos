#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
char ans[100];int num;
void print()
{
	if(strcmp(ans,"impossible")==0)
	{
		printf("%s",ans);
		return;
	}
	int n=strlen(ans);
	for(int i=0;i<n;i++)
	{
		if(ans[i]>='A'&&ans[i]<='Z')
		{
			if(ans[i+1]=='B')
			{
				if(num==2)printf("AB+,AB-");
				if(num==0)printf("AB-");
				if(num==1)printf("AB+");
				i++;
			}
			else
			{
				if(num==2)printf("%c+,%c-",ans[i],ans[i]);
				if(num==0)printf("%c-",ans[i]);
				if(num==1)printf("%c+",ans[i]);
			}
		}
		else 
		{
			if((ans[i]=='{'||ans[i]=='}')&&num!=2&&(n==3))continue;
			printf("%c",ans[i]);
		}
	}
}
int main()
{
	int T;scanf("%d",&T);
	char a[5],b[5],c[5],a1,b1,c1;
	while(T--)
 {
	scanf("%s%s%s",a,b,c);
	int na=strlen(a),nb=strlen(b),nc=strlen(c);
	a1=a[na-1];b1=b[nb-1];c1=c[nc-1];
	if(a[0]!='?')na--;if(b[0]!='?')nb--;if(c[0]!='?')nc--;
	if(a[0]=='O'&&b[0]=='O')strcpy(ans,"{O}");
	else if((a[0]=='O'&&c[0]=='O')||(b[0]=='O'&&c[0]=='O'))strcpy(ans,"{A,B,O}");
	else if((a[0]=='O'&&b[0]=='B')||(a[0]=='B'&&b[0]=='O'))strcpy(ans,"{B,O}");
	else if(a[0]=='A'&&b[0]=='A'&&na==1&&nb==1)strcpy(ans,"{A,O}");
	else if((a[0]=='A'&&b[0]=='B'&&na==1)||(a[0]=='B'&&b[0]=='A'&&nb==1))strcpy(ans,"{A,AB,B,O}");
	else if(a[0]=='B'&&b[0]=='B')strcpy(ans,"{B,O}");
	else if(na==2&&nb==2)strcpy(ans,"{A,AB,B}");
	else if((a[0]=='A'&&na==1&&nb==2)||(na==2&&b[0]=='A'&&nb==1))strcpy(ans,"{A,AB,B}");
	else if((a[0]=='B'&&nb==2)||(na==2&&b[0]=='B'))strcpy(ans,"{A,AB,B}");
	else if((a[0]=='B'&&c[0]=='B')||(b[0]=='B'&&c[0]=='B'))strcpy(ans,"{A,AB,B,O}");
	else if(nc==2&&(na==2||nb==2))strcpy(ans,"{A,AB,B}");
	else if(nc==2&&((a[0]=='A'&&na==1)||(b[0]=='A'&&nb==1)))strcpy(ans,"{AB,B}");
	else if(c[0]=='A'&&nc==1&&(na==2||nb==2))strcpy(ans,"{A,AB,B,O}");
	else if(c[0]=='B'&&(na==2||nb==2))strcpy(ans,"{A,AB,B,O}");
	else if(nc==2&&(a[0]=='B'||b[0]=='B'))strcpy(ans,"{A,AB}");
	else if((a[0]=='A'&&na==1&&b[0]=='O')||(a[0]=='O'&&b[0]=='A'&&nb==1))strcpy(ans,"{A,O}");
	else if((a[0]=='B'&&b[0]=='O')||(a[0]=='O'&&b[0]=='A'&&nb==1))strcpy(ans,"{B,O}");
	else if((na==2&&b[0]=='O')||(a[0]=='O'&&nb==2))strcpy(ans,"{A,B}");
	else if(c[0]=='O'&&((na==1&&a[0]=='A')||(nb==1&&b[0]=='A')||a[0]=='B'||b[0]=='B')&&na!=2&&nb!=2)strcpy(ans,"{A,B,O}");
	else if(c[0]=='A'&&nc==1&&((a[0]=='A'&&na==1)||(b[0]=='A'&&nb==1)))strcpy(ans,"{A,AB,B,O}");
	else if(c[0]=='A'&&nc==1&&(a[0]=='B'||b[0]=='B'))strcpy(ans,"{A,AB}");
	else if(c[0]=='A'&&nc==1&&(a[0]=='O'||b[0]=='O'))strcpy(ans,"{A,AB}");
	else if(c[0]=='B'&&(a[0]=='O'||b[0]=='O'))strcpy(ans,"{AB,B}");
	else if(c[0]=='B'&&((a[0]=='A'&&na==1)||(b[0]=='A'&&nb==1)))strcpy(ans,"{AB,B}");
	else strcpy(ans,"impossible");	
 
 	if(c1=='?')
 	{
 		if(a1=='-'&&b1=='-')num=0;//-
 		else num=2;//+ -
	}
	if(a1=='?')
	{
		if(c1=='-')num=2;
		else 
		{
			if(b1=='-')num=1;//+
			else num=2;
		}
	}
	if(b1=='?')
	{
		if(c1=='-')num=2;
		else 
		{
			if(a1=='-')num=1;//+
			else num=2;
		}
	}
	if(a[0]=='?')print();else printf("%s",a);printf(" ");
	if(b[0]=='?')print();else printf("%s",b);printf(" ");
	if(c[0]=='?')print();else printf("%s",c);if(T)printf("\n");
 }
	return 0;
}