#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
long long ATOI(char a[])
{if(a[0]=='0') return 0;
	long long ans=0;
	int l=strlen(a);
	if(a[0]=='-')
	{
		int i=1;
		while(i<l) ans=ans*10+(a[i++]-'0');
		ans*=-1;
	}
	else
	{
		int i=0;
		while(i<l) ans=ans*10+(a[i++]-'0');//,printf("%d\n",ans);;
	}
	
	return ans;
}

int main()
{
	long long ax=0,bx=0,cx=0,dx=0;
	char Ord[10],ord[10];int i=0;
	while(scanf("%s %s",Ord,ord)!=EOF)
	{	//printf("%s %s\n",Ord,ord);
		//printf("%d\n",i++);
		char bl1[10],bl2[10];
		int b1=0,b2=0;
		while(ord[b1]!=','&&b1<strlen(ord)) bl1[b1]=ord[b1],b1+=1;//,printf("%c\n",bl1[b1-1]);
		bl1[b1++]='\0';
		while(b1<strlen(ord)) bl2[b2]=ord[b1],b1++,b2++;
		bl2[b2]='\0';
		//printf("%s %s %s\n",Ord,bl1,bl2);
		if(strcmp(Ord,"OUT\0")==0)
		{//printf("------\n");
			if(bl1[0]=='A') printf("%lld\n",ax);
			else if(bl1[0]=='B') printf("%lld\n",bx);
			else if(bl1[0]=='C') printf("%lld\n",cx);
			else if(bl1[0]=='D') printf("%lld\n",dx);
			//ax=0;bx=0;cx=0;dx=0;
		}
		else if(strcmp(Ord,"IN\0")==0) 
		{//printf("%s\n",bl2);
			long long ans=ATOI(bl2);//printf("ans:%lld\n",ans);
			if(bl1[0]=='A') ax=ans;
			else if(bl1[0]=='B') bx=ans;
			else if(bl1[0]=='C') cx=ans;
			else if(bl1[0]=='D') dx=ans;
		}
		else if(strcmp(Ord,"MOV\0")==0)
		{
			if(bl1[0]=='A')
			{
				if(bl2[0]=='B') ax=bx;
				else if(bl2[0]=='C') ax=cx;
				else if(bl2[0]=='D') ax=dx;
			}
			else if(bl1[0]=='B')
			{
				if(bl2[0]=='A') bx=ax;
				else if(bl2[0]=='C') bx=cx;
				else if(bl2[0]=='D') bx=dx;
			}
			else if(bl1[0]=='C')
			{
				if(bl2[0]=='B') cx=bx;
				else if(bl2[0]=='A') cx=ax;
				else if(bl2[0]=='D') cx=dx;
			}
			else if(bl1[0]=='D')
			{
				if(bl2[0]=='B') dx=bx;
				else if(bl2[0]=='C') dx=cx;
				else if(bl2[0]=='A') dx=ax;
			}
			
		}
		else if(strcmp(Ord,"ADD\0")==0)
		{
			if(bl1[0]=='A')
			{
				if(bl2[0]=='B') ax=ax+bx;
				else if(bl2[0]=='C') ax=ax+cx;
				else if(bl2[0]=='D') ax=ax+dx;
				else if(bl2[0]=='A') ax=2*ax;
			}
			else if(bl1[0]=='B')
			{
				if(bl2[0]=='A') bx=bx+ax;
				else if(bl2[0]=='B') bx=2*bx;
				else if(bl2[0]=='C') bx=bx+cx;
				else if(bl2[0]=='D') bx=bx+dx;
			}
			else if(bl1[0]=='C')
			{
				if(bl2[0]=='B') cx=cx+bx;
				else if(bl2[0]=='C') cx=2*cx;
				else if(bl2[0]=='A') cx=cx+ax;
				else if(bl2[0]=='D') cx=cx+dx;
			}
			else if(bl1[0]=='D')
			{
				if(bl2[0]=='B') dx=dx+bx;
				else if(bl2[0]=='D') dx=2*dx;
				else if(bl2[0]=='C') dx=dx+cx;
				else if(bl2[0]=='A') dx=dx+ax;
			}
			
		}
		else if(strcmp(Ord,"SUB\0")==0)
		{
			if(bl1[0]=='A')
			{
				if(bl2[0]=='B') ax=ax-bx;
				else if(bl2[0]=='A') ax=0;
				else if(bl2[0]=='C') ax=ax-cx;
				else if(bl2[0]=='D') ax=ax-dx;
			}
			else if(bl1[0]=='B')
			{
				if(bl2[0]=='A') bx=bx-ax;
				else if(bl2[0]=='B') bx=0;
				else if(bl2[0]=='C') bx=bx-cx;
				else if(bl2[0]=='D') bx=bx-dx;
			}
			else if(bl1[0]=='C')
			{
				if(bl2[0]=='B') cx=cx-bx;
				else if(bl2[0]=='C') cx=0;
				else if(bl2[0]=='A') cx=cx-ax;
				else if(bl2[0]=='D') cx=cx-dx;
			}
			else if(bl1[0]=='D')
			{
				if(bl2[0]=='B') dx=dx-bx;
				else if(bl2[0]=='D') dx=0;
				else if(bl2[0]=='C') dx=dx-cx;
				else if(bl2[0]=='A') dx=dx-ax;
			}
			
		}
		else if(strcmp(Ord,"MUL\0")==0)
		{
			if(bl1[0]=='A')
			{
				if(bl2[0]=='B') ax=ax*bx;
				else if(bl2[0]=='A') ax=ax*ax;
				else if(bl2[0]=='C') ax=ax*cx;
				else if(bl2[0]=='D') ax=ax*dx;
			}
			else if(bl1[0]=='B')
			{
				if(bl2[0]=='A') bx=bx*ax;
				else if(bl2[0]=='B') bx=bx*bx;
				else if(bl2[0]=='C') bx=bx*cx;
				else if(bl2[0]=='D') bx=bx*dx;
			}
			else if(bl1[0]=='C')
			{
				if(bl2[0]=='B') cx=cx*bx;
				else if(bl2[0]=='C') cx=cx*cx;
				else if(bl2[0]=='A') cx=cx*ax;
				else if(bl2[0]=='D') cx=cx*dx;
			}
			else if(bl1[0]=='D')
			{
				if(bl2[0]=='B') dx=dx*bx;
				else if(bl2[0]=='D') dx=dx*dx;
				else if(bl2[0]=='C') dx=dx*cx;
				else if(bl2[0]=='A') dx=dx*ax;
			}
			
		}
		else if(strcmp(Ord,"DIV\0")==0)
		{
			if(bl1[0]=='A')
			{
				if(bl2[0]=='B') ax=ax/bx;
				else if(bl2[0]=='A') ax=1;
				else if(bl2[0]=='C') ax=ax/cx;
				else if(bl2[0]=='D') ax=ax/dx;
			}
			else if(bl1[0]=='B')
			{
				if(bl2[0]=='A') bx=bx/ax;
				else if(bl2[0]=='B') bx=1;
				else if(bl2[0]=='C') bx=bx/cx;
				else if(bl2[0]=='D') bx=bx/dx;
			}
			else if(bl1[0]=='C')
			{
				if(bl2[0]=='B') cx=cx/bx;
				else if(bl2[0]=='C') cx=1;
				else if(bl2[0]=='A') cx=cx/ax;
				else if(bl2[0]=='D') cx=cx/dx;
			}
			else if(bl1[0]=='D')
			{
				if(bl2[0]=='B') dx=dx/bx;
				else if(bl2[0]=='D') dx=1;
				else if(bl2[0]=='C') dx=dx/cx;
				else if(bl2[0]=='A') dx=dx/ax;
			}
			
		}
		
	}
	return 0;
}