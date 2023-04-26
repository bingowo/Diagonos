#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int tab[22225];
int main()
{
	char s[1005];
	int ct=0,T;scanf("%d",&T);
	tab[12]='A';tab[2111]='B';tab[2121]='C';tab[211]='D';tab[1]='E';tab[1121]='F';tab[221]='G';tab[1111]='H';tab[11]='I';tab[1222]='J';tab[212]='K';tab[1211]='L';tab[22]='M';tab[21]='N';tab[222]='O';tab[1221]='P';tab[2212]='Q';tab[121]='R';tab[111]='S';tab[2]='T';tab[112]='U';tab[1112]='V';tab[122]='W';tab[2112]='X';tab[2122]='Y';tab[2211]='Z';
	tab[22222]='0';tab[12222]='1';tab[11222]='2';tab[11122]='3';tab[11112]='4';tab[11111]='5';tab[21111]='6';tab[22111]='7';tab[22211]='8';tab[22221]='9';
	while(T--)
	{
		scanf("%s",s);
		printf("case #%d:\n",ct++);
		int n=strlen(s),x=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='.')x=x*10+1;
			if(s[i]=='-')x=x*10+2;
			if(s[i]=='/'||i==n-1)
			{
				if(i+4<n&&s[i+4]=='/'&&s[i+3]=='/'&&s[i+2]=='/'&&s[i+1]=='/')
				{printf("%c.",tab[x]);i+=4;}
				else if(i+2<n&&s[i+2]=='/'&&s[i+1]=='/')
				{printf("%c ",tab[x]);i+=2;}
				else printf("%c",tab[x]);
				x=0;
			}
		}
		printf("\n");
	}
	return 0;
}