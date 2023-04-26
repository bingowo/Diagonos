#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
int ATO(char a[])
{if(a[3]=='0') return 0;
	int ans=0;
	int l=strlen(a);
	if(a[3]=='-')
	{
		int i=4;
		while(i<l) ans=ans*10+(a[i++]-'0');
		ans*=-1;
	}
	else
	{
		int i=3;
		while(i<l) ans=ans*10+(a[i++]-'0');//,printf("%d\n",ans);;
	}
	
	return ans;
}

int main()
{
	char Ord[20],ord[100];
	int oud[30];
	for(int i=0;i<30;i++) oud[i]=0;
	
	
	while(scanf("%s %s",Ord,ord)!=EOF)
	{	
		int len=strlen(ord);
		if(strcmp(Ord,"OUT")==0) printf("%d\n",oud[ord[0]-'A']);
		else if(strcmp(Ord,"IN")==0) oud[ord[0]-'A']=ATO(ord);//,printf("atoi:%d\n",ATO(ord));
		else if(strcmp(Ord,"MOV")==0) oud[ord[0]-'A']=oud[ord[3]-'A'];
		else if(strcmp(Ord,"ADD")==0)
		{
			if(len>6) oud[ord[0]-'A']=oud[ord[3]-'A']+oud[ord[6]-'A'];
			else if(len<6) oud[ord[0]-'A']=oud[ord[0]-'A']+oud[ord[3]-'A'];
		}
		else if(strcmp(Ord,"SUB")==0)
		{
			if(len>6) oud[ord[0]-'A']=oud[ord[3]-'A']-oud[ord[6]-'A'];
			else if(len<6) oud[ord[0]-'A']=oud[ord[0]-'A']-oud[ord[3]-'A'];
		}
		else if(strcmp(Ord,"MUL")==0)
		{
			if(len>6) oud[ord[0]-'A']=oud[ord[3]-'A']*oud[ord[6]-'A'];
			else if(len<6) oud[ord[0]-'A']*=oud[ord[3]-'A'];
		}
		else if(strcmp(Ord,"DIV")==0)
		{
			if(len>6) oud[ord[0]-'A']=oud[ord[3]-'A']/oud[ord[6]-'A'];
			else if(len<6) oud[ord[0]-'A']/=oud[ord[3]-'A'];
		}
		else if(strcmp(Ord,"OR")==0)
		{
			if(len>6) oud[ord[0]-'A']=oud[ord[3]-'A']|oud[ord[6]-'A'];
			else if(len<6) oud[ord[0]-'A']=oud[ord[0]-'A']|oud[ord[3]-'A'];
		}
		else if(strcmp(Ord,"MOD")==0)
		{
			if(len>6) oud[ord[0]-'A']=oud[ord[3]-'A']%oud[ord[6]-'A'];
			else if(len<6) oud[ord[0]-'A']%=oud[ord[3]-'A'];
		}
		else if(strcmp(Ord,"AND")==0)
		{
			if(len>6) oud[ord[0]-'A']=oud[ord[3]-'A']&oud[ord[6]-'A'];
			else if(len<6) oud[ord[0]-'A']=oud[ord[0]-'A']&oud[ord[3]-'A'];
		}
		else if(strcmp(Ord,"XOR")==0)
		{
			if(len>6) oud[ord[0]-'A']=oud[ord[3]-'A']^oud[ord[6]-'A'];
			else if(len<6) oud[ord[0]-'A']=oud[ord[0]-'A']^oud[ord[3]-'A'];
		}
		else if(strcmp(Ord,"XCHG")==0)
		{
		    int tump=oud[ord[0]-'A'];
		    oud[ord[0]-'A']=oud[ord[3]-'A'];
		    oud[ord[3]-'A']=tump;
		}
		//printf("%d %d %d %d\n",oud[0],oud[1],oud[2],oud[3]);
	}
	return 0;
}