#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int main()
{
	int H,M,S,SS,hx;
	int ansH=0,ansM=0,ansS=0;
	char s[1005],HX[100];
	while(1)
	{
		int sum;
		scanf("%s",s);
		if(strcmp(s,"END")==0)
		{
			ansH=(ansH+8)%24;
			if(ansH<10)printf("0");
			printf("%d:",ansH);
			if(ansM<10)printf("0");
			printf("%d:",ansM);
			if(ansS<10)printf("0");
			printf("%d\n",ansS);
			break;
		}
		//printf("%s\n",s);
		int n=strlen(s),pos=0;
		//while(pos<n)
		//{
			int comma=1;
			if(s[pos]=='$'&&s[pos+1]=='G'&&s[pos+2]=='P'&&s[pos+3]=='R'&&s[pos+4]=='M'&&s[pos+5]=='C')
			{
				sum=((((((((('G'^'P')%65536)^'R')%65536)^'M')%65536)^'C')%65536)^',')%65536;
				pos+=7;//printf("%c\n",s[pos]);
				H=(s[pos]-'0')*10+s[pos+1]-'0';
				M=(s[pos+2]-'0')*10+s[pos+3]-'0';
				S=(s[pos+4]-'0')*10+s[pos+5]-'0';
				sum=(sum^s[pos])%65536;sum=(sum^s[pos+1])%65536;sum=(sum^s[pos+2])%65536;sum=(sum^s[pos+3])%65536;sum=(sum^s[pos+4])%65536;sum=(sum^s[pos+5])%65536;
				pos+=6;//printf("%c\n",s[pos]);
				while(pos<n&&s[pos]!='*')
				{
					if(s[pos]==',')comma++;
					if(comma==2&&s[pos]=='V'&&s[pos-1]==',')break;
					sum=(sum^s[pos])%65536;++pos;
				}
				hx=0;pos++;
				while(sum)
				{
					int x=sum%16;
					if(x>=10)HX[++hx]=x-10+'A';
					else HX[++hx]=x+'0';
					sum/=16;//printf("%c\n",HX[hx]);
				}
				while(pos<n&&hx>0)
				{
					if(s[pos++]!=HX[hx--])break;
					if(pos==n&&hx==0)
					{
						ansH=H;ansM=M;ansS=S;
					}
				}
			}
		//}
	}
}