#include<stdio.h>
#include<string.h>
const int ABO[4][4][4]=
{1,0,0,1, 1,1,1,0, 1,1,1,1, 1,0,0,1,
 1,1,1,0, 1,1,1,0, 1,1,1,0, 1,0,1,0,
 1,1,1,1, 1,1,1,0, 0,0,1,1, 0,0,1,1,
 1,0,0,1, 1,0,1,0, 0,0,1,1, 0,0,0,1};
 //Abo[i][j][k]表示血型为i的父亲和血型为j的母亲可以生出血型为k的孩子
 // 血型A—0，血型AB—1, 血型B—2，血型O—3 
 const int Rh[2][2][2]=
 {1,1, 1,1,
  1,1, 0,1};
 //Rh[i][j][k]：表示Rh为 i 的父亲和 Rh为 j 的母亲是否可以生出Rh为 k 的孩子。
 //Rh+ : 0，Rh-: 1
int ans_ABO[4];//ans_ABO[i], 表示血型i是否为可能的血型,i=0: 血型A， 1: 血型AB, 2:血型B， 3: 血型O
int ans_Rh[2];//ans_Rh[i] ,表示Rh为i是否可能出现,i=0: Rh+ ， 1: Rh-
	
 int read()
 {
 	char s[10];
 	scanf("%s",s);
 	int flag=0;
 	if(!strcmp(s,"A+"))flag=1;//这里是从1开始的，所以对应到数组的时候要-1 
 	else if(!strcmp(s,"A-"))flag=-1;//负数代表Rh- 
 	else if(!strcmp(s,"B+"))flag=3;
 	else if(!strcmp(s,"B-"))flag=-3;
 	else if(!strcmp(s,"AB+"))flag=2;
 	else if(!strcmp(s,"AB-"))flag=-2;
 	else if(!strcmp(s,"O+"))flag=4;
 	else if(!strcmp(s,"O-"))flag=-4;
 	else if(!strcmp(s,"?"))flag=0;
 	return flag;
 }
 void print(int x,int type)
 {
 	if(type==1)printf("{");
 	else if(type>1)printf(",");
 	if(x==1||x==-1)printf("A");
 	if(x==2||x==-2)printf("AB");
 	if(x==3||x==-3)printf("B");
 	if(x==4||x==-4)printf("O");
 	if(x>0)printf("+");
 	else printf("-");
 	
 }
 void write()
 {
 	int ABO=0,Rh=0;
 	for(int i=0;i<4;i++)//统计可能的ABO血型数 
 	{
 		ABO+=ans_ABO[i];
	 }
	 for(int j=0;j<4;j++)//统计可能的Rh因子数，可能的血型数为ABO*Rh 
	 {
	 	Rh+=ans_Rh[j]; 
	 }
	 if(ABO*Rh==0)printf("impossible");
	 if(ABO*Rh==1)//只有一种血型
	 {
	 	for(int i=0;i<4;i++)
	 	{
	 		if(ans_ABO[i]>0)
	 		{
	 			for(int j=0;j<2;j++)
	 			{
	 				if(ans_Rh[j]>0)
	 				{
	 					if(j==0)print(i+1,0);
	 					else print(-i-1,0);
					 }
				 }
			 }
		 }
	  } 
	  if(ABO*Rh>1)//有多种血型 
	  {
	  	int cnt=0;
	  	for(int i=0;i<4;i++)
	  	{
	  		if(ans_ABO[i]>0)
	  		{
	  			for(int j=0;j<2;j++)
	  			{
	  				if(ans_Rh[j])
	  				{
	  					cnt++;
	  					if(j==0)print(i+1,cnt);
	  					else print(-i-1,cnt);
					  }
				  }
			  }

		  }
		  printf("}");
	  }
 }
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
	int father,mother,child;
	father=read();
	mother=read();
	child=read();
	if(father==0)
	{
		int m1,c1,m2,c2;
		if(mother>0)//Rh+
		{
			m1=mother-1;
			m2=0;//标记Rh为+ 
		}
		else
		{
			m1=-mother-1;
			m2=1;
		}
		if(child>0)
		{
			c1=child-1;
			c2=0;
		} 
		else
		{
			c1=-child-1;
			c2=1;
		}
		
		for(int i=0;i<4;i++)//分别求出ABO血型和RH型的可能血型 
		{
			ans_ABO[i]=ABO[i][m1][c1];//c1代表小格子里的哪一个 
		 } 
		for(int i=0;i<2;i++)
		{
			ans_Rh[i]=Rh[i][m2][c2];
		}
	}
	if(mother==0)
	{
		int m1,c1,m2,c2;
		if(father>0)//Rh+
		{
			m1=father-1;
			m2=0;//标记Rh为+ 
		}
		else
		{
			m1=-father-1;
			m2=1;
		}
		if(child>0)
		{
			c1=child-1;
			c2=0;
		} 
		else
		{
			c1=-child-1;
			c2=1;
		}
		
		for(int i=0;i<4;i++)//分别求出ABO血型和RH型的可能血型 
		{
			ans_ABO[i]=ABO[m1][i][c1]; 
		 } 
		for(int i=0;i<2;i++)
		{
			ans_Rh[i]=Rh[m2][i][c2];
		}
	}
	if(child==0)
	{
		int m1,c1,m2,c2;
		if(mother>0)//Rh+
		{
			m1=mother-1;
			m2=0;//标记Rh为+ 
		}
		else
		{
			m1=-mother-1;
			m2=1;
		}
		if(father>0)
		{
			c1=father-1;
			c2=0;
		} 
		else
		{
			c1=-father-1;
			c2=1;
		}
		
		for(int i=0;i<4;i++)//分别求出ABO血型和RH型的可能血型 
		{
			ans_ABO[i]=ABO[c1][m1][i];
		 } 
		for(int i=0;i<2;i++)
		{
			ans_Rh[i]=Rh[c2][m2][i];
		}
	
	}
		if(father!=0)print(father,0);
		else write();
		printf(" ");
		if(mother!=0)print(mother,0);
		else write();
		printf(" ");
		if(child!=0)print(child,0);
		else write();
		printf("\n");
	
}
}