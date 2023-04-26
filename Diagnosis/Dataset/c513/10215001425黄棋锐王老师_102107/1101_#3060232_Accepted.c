#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const int ABO[4][4][4]=
//血型A—0，血型AB—1, 血型B—2，血型O—3
//ABO[i][j][k]表示血型为 i 的父亲和血型为 j 的母亲是否可以生出血型为  k 的孩子。
{ 1,0,0,1,  1,1,1,0,  1,1,1,1,  1,0,0,1,
1,1,1,0,   1,1,1,0,   1,1,1,0,  1,0,1,0,
 1,1,1,1,  1,1,1,0,    0,0,1,1,  0,0,1,1, 
1,0,0,1,   1,0,1,0,    0,0,1,1,  0,0,0,1
};

const int Rh[2][2][2]=
//Rh+ : 0，Rh-: 1 
//Rh[i][j][k]：表示Rh为 i 的父亲和 Rh为 j 的母亲是否可以生出Rh为  k 的孩子。
{1,1, 1,1,
 1,1, 0,1,
};

int ansABO[4]={0},ansRh[2]={0};//记录此次未知值
 
int read()
{
	char s[10]={'\0'};
	scanf("%s",s);//scanf以空格为界线 
	int flag=0;
	if(!strcmp(s,"A+")) flag=1;
	else if(!strcmp(s,"A-")) flag=-1;
	else if(!strcmp(s,"B+")) flag=3;
	else if(!strcmp(s,"B-")) flag=-3;
	else if(!strcmp(s,"AB+")) flag=2;
	else if(!strcmp(s,"AB-")) flag=-2;
	else if(!strcmp(s,"O+")) flag=4;
	else if(!strcmp(s,"O-")) flag=-4;
	else if(!strcmp(s,"?")) flag=0;
	return flag;
}

void print(int x,int type)
{
	if(type==1) printf("{");//输出{}和， 
	else if(type>1) printf(",");
	
	if(x==1||x==-1) printf("A");
	if(x==2||x==-2) printf("AB");
	if(x==3||x==-3) printf("B");
	if(x==4||x==-4) printf("O");
	if(x>0) printf("+");
	else printf("-");
}

void write()
{	int i,j;
	int abo=0,rh=0;
	for(i=0;i<4;i++) abo+=ansABO[i];//统计可能的ABO类型数
	 for(i=0;i<2;i++) rh+=ansRh[i];//统计可能的+-数 
	//总的类型数=abo*rh；
	if(abo*rh==0) printf("impossible");
	if(abo*rh==1) 
	{
		for(i=0;i<4;i++)
			if(ansABO[i])
				for(j=0;j<2;j++)
				if(ansRh[j])
				{
				if(j==0) print(i+1,0);//输出类型不带{}
				else print(-1-i,0); 
				}
	}
	
	else if(abo*rh>1)//*****这里一定要写成else if********
	{	int cnt=0;
		for(i=0;i<4;i++)
			if(ansABO[i])
				for(j=0;j<2;j++)
				if(ansRh[j])
				{ cnt++;
				if(j==0) print(i+1,cnt);//输出类型带{}和， 
				else print(-1-i,cnt); 
				}
	printf("}");
	}
}

int main() 
{
	int T;
	scanf("%d",&T);
	while(T--)
 { int fa,mo,ch,i;
	fa=read();mo=read();ch=read();
	if(fa==0)//fa未知 
	{ int m1,m2,c1,c2;//m-mo,c-ch
	if(mo>0) m1=mo-1,m2=0;//阳性
	else m1= -1-mo,m2=1;//阴性 
	
	if(ch>0) c1=ch-1,c2=0;
	else c1= -1-ch,c2=1;
	
	for(i=0;i<4;i++)
		ansABO[i]=ABO[i][m1][c1];//记录种类 
	
	for(i=0;i<2;i++)
	    ansRh[i]=Rh[i][m2][c2];//阴阳 
	}
		
		
	if(mo==0)
	{int f1,f2,c1,c2;//f-fa,c-ch
	if(fa>0) f1=fa-1,f2=0;//阳性
	else f1= -1-fa,f2=1;//阴性 
	
	if(ch>0) c1=ch-1,c2=0;
	else c1= -1-ch,c2=1;
	
	for(i=0;i<4;i++)
		ansABO[i]=ABO[f1][i][c1];//记录种类 
	
	for(i=0;i<2;i++)
	    ansRh[i]=Rh[f2][i][c2];//阴阳 
	}
		
	if(ch==0)
	{int f1,f2,m1,m2;//f-fa,m-mo
	if(fa>0) f1=fa-1,f2=0;//阳性
	else f1= -1-fa,f2=1;//阴性 
	
	if(mo>0) m1=mo-1,m2=0;//阳性
	else m1= -1-mo,m2=1;//阴性
	
	for(i=0;i<4;i++)
		ansABO[i]=ABO[f1][m1][i];//记录种类 
	
	for(i=0;i<2;i++)
	    ansRh[i]=Rh[f2][m2][i];//阴阳 
	}
	
	if(fa!=0) print(fa,0);else write();
	printf(" ");
	if(mo!=0) print(mo,0);else write();
	printf(" ");
	if(ch!=0) print(ch,0);else write();
	printf("\n");
 }
    return 0;
}
