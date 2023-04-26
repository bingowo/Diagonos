#include<stdio.h>
#include<string.h>
//A:0 AB:1 B:2 O:3
const int ABO[4][4][4]=
{1,0,0,1, 1,1,1,0, 1,1,1,1, 1,0,0,1,//ABO[0][0~3]father:A,mother:A,AB,B,O; 
 1,1,1,0, 1,1,1,0, 1,1,1,0, 1,0,1,0,//ABO[1][0~3]father:AB,mother:A,AB,B,O;
 1,1,1,1, 1,1,1,0, 0,0,1,1, 0,0,1,1,//ABO[2][0~3]father:B,mother:A,AB,B,O;
 1,0,0,1, 1,0,1,0, 0,0,1,1, 0,0,0,1 //ABO[3][0~3]father:O,mother:A,AB,B,O;
};
int get_index(const char* s)
{
	if(strcmp(s,"A")==0)return 0;
	else if(strcmp(s,"AB")==0)return 1;
	else if(strcmp(s,"B")==0)return 2;
	else return 3;
}
int main()
{
	char f[3],m[3],s[3];
	int F,M,S,i,j,k,af=0,abf=0,bf=0,of=0;
	scanf("%s%s%s",f,m,s);
	if(f[0]=='?')
	{
		M=get_index(m);
		S=get_index(s);
		for(i=0;i<4;i++)
		{
			if(ABO[i][M][S]==1&&i==0)af=1;
			if(ABO[i][M][S]==1&&i==1)abf=1;
			if(ABO[i][M][S]==1&&i==2)bf=1;
			if(ABO[i][M][S]==1&&i==3)of=1;
		}
		if(af==0&&abf==0&&bf==0&&of==0){printf("impossible %s %s",m,s);return 0;}
		else
		{
			printf("{");
			if(af==1&&abf==0&&bf==0&&of==0)printf("A"); else if(af==1)printf("A,");
			if(abf==1&&bf==0&&of==0)printf("AB"); else if(abf==1)printf("AB,");
			if(bf==1&&of==0)printf("B"); else if(bf==1)printf("B,");
			if(of==1)printf("O} %s %s",m,s); else printf("} %s %s",m,s);
			return 0;
		}
	}
	else if(m[0]=='?')
	{
		F=get_index(f);
		S=get_index(s);
		for(j=0;j<4;j++)
		{
			if(ABO[F][j][S]==1&&j==0)af=1;
			if(ABO[F][j][S]==1&&j==1)abf=1;
			if(ABO[F][j][S]==1&&j==2)bf=1;
			if(ABO[F][j][S]==1&&j==3)of=1;
		}
		if(af==0&&abf==0&&bf==0&&of==0){printf("%s impossible %s",f,s);return 0;}
		else
		{
			printf("%s {",f);
			if(af==1&&abf==0&&bf==0&&of==0)printf("A"); else if(af==1)printf("A,");
			if(abf==1&&bf==0&&of==0)printf("AB"); else if(abf==1)printf("AB,");
			if(bf==1&&of==0)printf("B"); else if(bf==1)printf("B,");
			if(of==1)printf("O} %s",s); else printf("} %s",s);
			return 0;
		}
	}
	else
	{
		F=get_index(f);
		M=get_index(m);
		for(k=0;k<4;k++)
		{
			if(ABO[F][M][k]==1&&k==0)af=1;
			if(ABO[F][M][k]==1&&k==1)abf=1;
			if(ABO[F][M][k]==1&&k==2)bf=1;
			if(ABO[F][M][k]==1&&k==3)of=1;
		}
		printf("%s %s {",f,m);
		if(af==1&&abf==0&&bf==0&&of==0)printf("A"); else if(af==1)printf("A,");
		if(abf==1&&bf==0&&of==0)printf("AB"); else if(abf==1)printf("AB,");
		if(bf==1&&of==0)printf("B"); else if(bf==1)printf("B,");
		if(of==1)printf("O}"); else printf("}");
		return 0;
		
	}
}