#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i_len=0,f_len=0;

struct BIG
{
	char s[1000];
	int in[500];//整数部分 
	int i_l;
	int f[500];//小数部分 
	int f_l;
	int point;//小数点位置 
}; 

struct BIG init(struct BIG a)//初始化 
{
	memset(a.in ,0,sizeof(a.in));
	memset(a.f ,0,sizeof(a.f));
	int i=0,j=0;
	while(a.s[i]!='.'&&a.s[i]!='\0')
	{
		i++;
	}
	a.point =i;//小数点位置 
	if(a.point==0)//没有整数
	{
		a.point=1;
	}
	if(a.s[i]=='\0')
	{
		a.point =strlen(a.s);
	 } 
	
	for(int i1=0;i1<a.point;i1++)
	{
		if(a.s [0]=='.')//整数部分为0 
		{
			break;
		}
		a.in[i1]=a.s[a.point-i1-1]-'0';//整数部分倒着存	
	}
	a.i_l =a.point;//整数部分长度 
	
	int len=strlen(a.s );
	for(int j1=a.point+1,j2=0;j1<len;j1++,j2++)
	{
		a.f [j2]=a.s[j1]-'0';//小数部分顺着存 
	}
	a.f_l =len-a.point-1;//小数长度 
	return a;
}

void sub(struct BIG a,struct BIG b,int i_len,int f_len,int exa)
{
	for(int j=0;j<i_len;j++)//整数减法 a=a-b
	{
		a.in[j]-=b.in[j];
	}
	for(int i=0;i<f_len;i++)//小数减法 
	{
		a.f[i]-=b.f[i];
	}
	
	for(int k=f_len-1;k>0;k--)//处理小数借位问题 
	{
		while(a.f[k]<0)
		{
			a.f[k]+=10;
			a.f[k-1]--;
		}
	}
	if(a.f[0]<0)
	{
		a.f[0]+=10;
		a.in[0]--;
	}
	
	for(int t=0;t<i_len;t++)//处理整数部分借位问题 
	{
		while(a.in[t]<0)
		{
			a.in[t]+=10;
			a.in[t+1]--;
		}
	}
	
	if(a.f[exa]>=5)//四舍五入 
	{
		a.f[exa-1]++;
	}
	for(int i1=exa-1;i1>0;i1-- )//解决入带来的进位问题
	{
		if(a.f[i1]>=10)
		{
			a.f[i1]-=10;
			a.f[i1-1]++;
		}
	 }
	 if(a.f[0]>=10)
	 {
	 	a.f[0]-=10;
	 	a.in[0]++;
	  }
	 for(int j1=0;j1<i_len-1;j1++)
	 {
	 	if(a.in[j1]>=10)
	 	{
	 		a.in[j1]-=10;
	 		a.in[j1+1]++;
		 }
	  } 
	if(a.in[i_len-1]>=10)
	{
		a.in[i_len-1]-=10;
		a.in[i_len]++;
		i_len++;
	}
	
	for(int n=i_len-1;n>=0;n--)//输出 
	{
		printf("%d",a.in[n]);
	}
	printf(".");
	for(int m=0;m<exa;m++)
	{
		printf("%d",a.f[m]);
	}
}


void MINUS(struct BIG a,struct BIG b,int exa)
{
	//printf("a.i_l,a.f_l:%d %d\n",a.i_l,a.f_l);
	 i_len=(a.i_l>b.i_l)?a.i_l:b.i_l;
	 f_len=(a.f_l>b.f_l)?a.f_l:b.f_l;
	
	int A=0;
	int B=0;
	for(int i=i_len-1;i>=0;i--)//判断整数部分大小 
	{
		if(a.in[i]>b.in[i])//从整数部分最高位开始比较 
		{
			A=1;
			break;
		}
		if(a.in[i]<b.in[i])
		{
			B=1;
			break;
		}
	}
	if(A==0&&B==0)//整数部分一样 
	{
		for(int i=0;i<f_len;i++)
		{
			if(a.f[i]>b.f[i])
			{
				A=1;
				break;
			}
			if(a.f[i]<b.f[i])
			{
				B=1;
				break;
			}
		}
	}
	if(A==0&&B==0)//小数部分也一样 
	{
		printf("0");
		printf(".");
		for(int i=0;i<exa;i++)
		{
			printf("0");
		}
	}
	

	if(A==1)//A>B,A-B
	{
		sub(a,b,i_len,f_len,exa);
	}
	if(B==1)
	{
		printf("-");
		sub(b,a,i_len,f_len,exa);
	}
}

int main()
{
	int exa;//小数点位数 
	struct BIG a;
	struct BIG b;
	scanf("%s",a.s );
	scanf("%s",b.s );
	scanf("%d",&exa);
	a=init(a);
	b=init(b);
//	printf("%d\n",a.point );
	MINUS(a,b,exa);//比较a,b大小并执行减法
	return 0;
	
}