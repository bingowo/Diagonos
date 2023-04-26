#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 200 

typedef struct
{	int sign;//符号 
	int cnt;//记录有效位数 
	int v[max];//记录每一位上的数字，v[0]个位，v[1]十位 
}BIGINT;// 表示最大可能位数小于N位的一个大正整数

BIGINT s2BIG(char*s)
{  int i,l=strlen(s);
	BIGINT R={1,0,{0}};
	for(i=l-1;i>=0;i--)
	{
		R.v[R.cnt++]=s[i]-'0';	
	}
	return R;
}
void BIG2s(char*s,BIGINT R)
{	int i,j=0;
	for(i=R.cnt-1;i>=0;i--)
	  s[j++]=R.v[i]+'0';
}

int cmp(const void*a,const void*b)//从小到大 
{	BIGINT aa=*(BIGINT*)a;
	BIGINT bb=*(BIGINT*)b;
	char sa[200]={'\0'};
	char sb[200]={'\0'};
	BIG2s(sa,aa);BIG2s(sb,bb);
	if(aa.sign==bb.sign)
	{ if(aa.sign==1) return strcmp(sa,sb);
		else return strcmp(sb,sa);
	}
	
	else
	{if(aa.sign==1&&bb.sign==-1) return 1;
	 else if(aa.sign==-1&&bb.sign==1) return -1;
	}
	
}

BIGINT A_B(BIGINT*A,BIGINT*B)//A-B
{   int carry=0,i=0;
	BIGINT R;
	for(i=0;i<A->cnt;i++)
	{   A->v[i]-=carry;
		if(A->v[i]<B->v[i]) 
		{
		carry=1;
		A->v[i]=A->v[i]+10-B->v[i];
		}
		else {
			carry=0;
			A->v[i]=A->v[i]-B->v[i];
		}
	}
	for(i=A->cnt-1;A->v[i]==0&&i>=0;i--);
	A->cnt=i+1;
	R=*A;
	return R;
}

BIGINT AaddB(BIGINT*A,BIGINT*B)//A+B
{   int carry=0,i=0,de=(A->cnt>B->cnt)?A->cnt:B->cnt;
	BIGINT R;
	for(i=0;i<de;i++)
	{   
		int t=A->v[i]+B->v[i]+carry;
		A->v[i]=t%10;
		carry=t/10;
	}
	while(carry>0)
	{	int t=A->v[i]+carry;
		A->v[i]=t%10;
		carry=t/10;
		i++;
	}
	if(i>A->cnt) A->cnt=i;
	R=*A;
	return R;
}

int main() 
{ 
	 int i,n;
	scanf("%d",&n);
	BIGINT spot[51]={{1,0,{0}}};
	for(i=0;i<51;i++) spot[i].sign=1;
	for(i=0;i<n;i++)
	{	char s[200]={'\0'};
		scanf("%s",s);
		if(s[0]!='-')
		{spot[i]=s2BIG(s);
		spot[i].sign=1;
		}
		else 
		{ char*p=s;
			p+=1;
		spot[i]=s2BIG(p);
		spot[i].sign=-1;
		}
	}
	qsort(spot,n,sizeof(spot[0]),cmp);
	BIGINT big=spot[n-1],small=spot[0],ans;
	char sa[200]={'\0'};
	char sb[200]={'\0'};
	BIG2s(sa,small);BIG2s(sb,big);
	if(small.sign==big.sign)
	{	if(strcmp(sa,sb)>0) ans=A_B(&small,&big);
		else if(strcmp(sa,sb)<0) ans=A_B(&big,&small);
		else if(strcmp(sa,sb)==0) ans.cnt=1,ans.v[0]=0;//***
	}
	else
	{
		ans=AaddB(&small,&big);
	}
	for(i=ans.cnt-1;i>=0;i--) printf("%d",ans.v[i]);
	return 0;
}