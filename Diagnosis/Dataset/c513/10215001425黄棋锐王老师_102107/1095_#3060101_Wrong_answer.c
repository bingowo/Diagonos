#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 3000 

typedef struct
{	int sign;
	int cnt;//记录有效位数 
	int v[max];//记录每一位上的数字，v[0]个位，v[1]十位 
}BIGINT;// 表示最大可能位数小于N位的一个大正整数

BIGINT int2BIG(int x)//把int转换成BIGINT 
{
	BIGINT R={1,0,{0}};
	do
	{
		R.v[R.cnt++]=x%10;
		x/=10;
	 } while(x>0);
	 return R;
}

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

int BIGcmp(BIGINT A,BIGINT B)
{ 	char a[200]={'\0'};
	char b[200]={'\0'};
	BIG2s(a,A);BIG2s(b,B);
	int la=strlen(a),lb=strlen(b),i;
	if(la>lb) return 1;
	else if(la<lb) return -1;
	else if(la==lb)
	{
	    for(i=0;i<la;i++)
	    {
	    	if(a[i]>b[i]) return 1;
	    	else if(a[i]<b[i]) return -1;
		}
		if(i==la) return 0;
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

BIGINT AaddB(BIGINT*A,BIGINT*B)//A+B,A,B为正整数 
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


BIGINT AJIAB(BIGINT qr,BIGINT qi)////处理qr+qi，带符号处理 
{	BIGINT f1;
	if(qr.sign==qi.sign)
		{f1=AaddB(&qr,&qi);
			if(qr.sign==1) f1.sign=1;
			else f1.sign=-1;
		}
		else//qr,qi异号 
		{ int flag=BIGcmp(qr,qi);
		if(qr.sign==1&&flag==1)//qr>0,qr+qi>0
			{  	f1=A_B(&qr,&qi);
				f1.sign=1; 
			}
		else if(qr.sign==1&&flag==-1)//qr>0,qr+qi<0
			{  	f1=A_B(&qi,&qr);
				f1.sign=-1; 
			}
		else if(qr.sign==-1&&flag==1)//qr<0,qr+qi<0
			{  	f1=A_B(&qr,&qi);
				f1.sign=-1; 
			}
		else if(qr.sign==-1&&flag==-1)//qr<0,qr+qi>0
			{  	f1=A_B(&qi,&qr);
				f1.sign=1; 
			}
		else if(flag==0) 
			{ f1.sign=1;f1.cnt=1;f1.v[0]=0;}	
		}
		
	return f1;
}

int main() 
{ 
	char s[2000]={'\0'};
	scanf("%s",s);
	char*p=s;
	p+=2;
	char x[1005]={'\0'};
	int j;
	while(*p)
	{  x[j++]=*p;
		p++;
	}
	//******x记录十六进制数 
	char er[1005]={'\0'};
	int k=0,i;
	for(i=0;i<strlen(x);i++)
	{  int d=0;//记录十六进制数的十进制数 
		unsigned int flag=8;//二进制的1000
		 if(x[i]>='A') d=x[i]+10-'A';
		 else d=x[i]-'0';
		 while(flag)// 十六进制转二进制,转换后二进制为倒序，k记录有效位数 
		 {
		 	if(d&flag) er[k++]='1';
		 	else er[k++]='0';
		 	flag>>=1;//1000>>0100>>0010>>0001
		 }
	}
	
	BIGINT qr={1,0,{0}},qi={1,0,{0}},r,qrr,qii,f1,f2;//a+bi=(qr+q1i)*(-1+i)+r得到a=-qr-qi+r,b=qr-qi 
	for(i=0;i<k;i++)
	{	
		r=int2BIG(er[i]-'0');
		f1=AJIAB(qr,qi);
		f1.sign*=-1;
		qrr=AJIAB(r,f1);
		qi.sign*=-1;
		qii=AJIAB(qr,qi);
		qr=qrr,qi=qii;
	}
	
	
	int flagr=-1,flagi=-1;//判断是否有实部和虚部 
		for(i=0;i<qr.cnt;i++)
		{	if(qr.v[i]!=0) break;
		}
		if(i<qr.cnt) flagr=1;
		 
		 for(i=0;i<qi.cnt;i++)
		{	if(qi.v[i]!=0) break;
		}
		if(i<qi.cnt) flagi=1;
		
		if(((qr.cnt==1&&qr.v[0]==0)||qr.cnt==0)&&((qi.cnt==1&&qi.v[0]==0)||qi.cnt==0)) printf("0");
		int flag=-1;
		if(flagr==1&&qr.sign==1&&!(qr.cnt==0||qr.cnt==1&&qr.v[0]==0))
		{	flag=1;
			for(i=qr.cnt-1;i>=0;i--) printf("%d",qr.v[i]);
		}
		 
		if(flagr==1&&qr.sign==-1&&!(qr.cnt==0||qr.cnt==1&&qr.v[0]==0))
		 { putchar('-');
		 	flag=1;
		 	for(i=qr.cnt-1;i>=0;i--) printf("%d",qr.v[i]);
		 }
		 
		if(flagi==1&&qi.sign==1&&!(qi.cnt==0||qi.cnt==1&&qi.v[0]==0))
		{	if(flag==1) printf("+");
			if(!(qi.cnt==1&&qi.v[0]==1))
			{for(i=qi.cnt-1;i>=0;i--) printf("%d",qi.v[i]);}
			putchar('i');
		}

		if(flagi==1&&qi.sign==-1&&!(qi.cnt==0||qi.cnt==1&&qi.v[0]==0))
		{	putchar('-');
			if(!(qi.cnt==1&&qi.v[0]==1))
			{for(i=qi.cnt-1;i>=0;i--) printf("%d",qi.v[i]);}
			putchar('i');
		}

	
	return 0;
}