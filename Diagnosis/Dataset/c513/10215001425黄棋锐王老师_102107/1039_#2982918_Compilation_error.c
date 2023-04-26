#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct//表达式，看作一个向量，cnt记录分量个数，分量的值放在数组中 
{
	int cnt;
	long long int data[50];
}Vector;

Vector var[20000];//向量名->ID,ID为数组下标
char item[50][10]={'\0'}; //储存表达式中的每一项，每一行表示一项 
Vector calc(int l,int r);//计算表达式，返回表达式结果
//void deal(int *l,int *r);//去除（l，r）外层的括号
//int isNum(char *s);//判断字符串s是否为数字，如果是则返回1，否则返回0 
//int isALLNum(int l,int r);//判断item[l]....item[r]是否全为数字，是返回1，否则返回0 
//long long int strToNum(char *s);//返回字符串s对应的整数
//Vector ADD(Vector m1,Vector m2);//两个向量进行+操作，m1+m2 
//Vector SUB(Vector m1,Vector m2);//两个向量进行-操作，m1-m2 
//Vector MUL(Vector m1,Vector m2);//两个向量进行*操作，m1*m2 
//Vector compADD(Vector m1);//进行+/操作：+/m1
//Vector compSUB(Vector m1);//进行-/操作：-/m1
//Vector compMUL(Vector m1);//进行*/操作：*/m1

int main()
{
	int N=0;scanf("%d",&N);getchar();
	for(int i=0;i<N;i++)//输入N行 ,一次处理一行 
	{
		char line[201]={'\0'};gets(line);
		int n=-1,t=0,flag=0;
		for(int k=0;line[k];k++)//将表达式的每一项解析出来储存在item数组中 
		{
			if(line[k]!=' ')
			{
				if(flag==0) { ++n;t=0;flag=1;}
				item[n][t++]=line[k];
			}
			else 
			{ if(flag==1) item[n][t]='\0';
				flag=0;
			}
		}
		item[n][t]='\0';
		
		Vector ans=calc(0,n);
		
		if(ans.cnt==-1) ans=var[ans.data[0]];
		for(int j=0;j<ans.cnt;j++)
		 		printf("%lld%c",ans.data[j],j==ans.cnt-1?'\n':' ');
	}
	return 0;
}

Vector calc(int l,int r)//计算表达式，返回表达式结果 
{
	deal(&l,&r);//去掉（l，r）的最外层括号
	Vector tmp; 
	
	if(isALLNum(l,r))//如果表达式全是数字，则将每个数字存贮在数组成员data中 
	{
		tmp.cnt=0;
		for(int i=1;i<=r;i++)
		{
			tmp.data[tmp.cnt++]=strToNum(item[i]);
		}
		return tmp;
	}
	
	if(l==r)//如果表达式是单个变量，将变量名转换为唯一整数ID值，储存在成员data中，设置cnt=-1； 
	{
		tmp.cnt=-1;
		long long int d=0;
		for(int i=0;item[l][i];i++)
		  d=d*26+(item[l][i]-'a'+1);
		tmp.data[0]=d;
		return tmp;
	} 
	
	int j=-1,t=0;
	for(int i=l;i<=r;i++)//查找最后运算的二元运算符位置，j标记 
	{
		if(strcmp(item[i],")")==0) ++t;
		else if(strcmp(item[i],"(")==0) --t;
		else if(t==0&&i>l&&(!strcmp(item[i],"+")||!strcmp(item[i],"-")||!strcmp(item[i],"*")||!strcmp(item[i],"=")))
	        {j=i;break;}
	}
	
	Vector opera1,opera2;
	
	if(strcmp(item[j],"=")==0)//最后操作是 = 运算 
	{
		opera2=calc(j+1,r);
		if(opera2.cnt==-1) opera2=var[opera2.data[0]];
		opera1=calc(l,j-1);
		var[opera1.data[0]]=opera2;
		return opera2;
	}
	
	if(strcmp(item[j],"+")==0)//最后操作是 + 运算 
	{
		opera2=calc(j+1,r);
		if(opera2.cnt==-1) opera2=var[opera2.data[0]];
		opera1=calc(l,j-1);
		if(opera1.cnt==-1) opera1=var[opera1.data[0]];
		return ADD(opera1,opera2);
	}
	
	if(strcmp(item[j],"-")==0)//最后操作是 - 运算 
	{
		opera2=calc(j+1,r);
		if(opera2.cnt==-1) opera2=var[opera2.data[0]];
		opera1=calc(l,j-1);
		if(opera1.cnt==-1) opera1=var[opera1.data[0]];
		return SUB(opera1,opera2);
	}
	
	if(strcmp(item[j],"*")==0)//最后操作是 * 运算 
	{
		opera2=calc(j+1,r);
		if(opera2.cnt==-1) opera2=var[opera2.data[0]];
		opera1=calc(l,j-1);
		if(opera1.cnt==-1) opera1=var[opera1.data[0]];
		return MUL(opera1,opera2);
	}
	if(strcmp(item[l+1],"/")==0)//最后操作是+/、-/、*/运算
	{
		opera1=calc(l+2,r);
		if(strcmp(item[l],"+")==0) return compADD(opera1);
		if(strcmp(item[l],"-")==0) return compSUB(opera1);
		if(strcmp(item[l],"*")==0) return compMUL(opera1);
	} 
} 
 
 void deal(int *l,int *r)//去除（l，r）外层的括号
 {
 	while(1)
 	{
 		if(strcmp(item[*l],"(")||strcmp(item[*r],")")) return;
 		int t=0;
 		for(int i=*l;i<=*r;i++)
 		{
 			if(strcmp(item[i],"(")==0) ++t;
 			else if(strcmp(item[i],")")==0) --t;
 			else if(t==0) return ;
		 }
		 ++(*l),--(*r);
	 }
 } 
 
 int isNum(char *s)//判断字符串s是否为数字，如果是则返回1，否则返回0 
 { 
   for(int i=0;s[i];i++)
   		if(s[i]<'0'||s[i]>'9') return 0;
   		return 1;
 }

 int isALLNum(int l,int r)//判断item[l]....item[r]是否全为数字，是返回1，否则返回0 
 {
 	for(int i=l;i<=r;i++)
 	    if(!isNum(item[i])) return 0;
 	    return 1;
 }

 long long int strToNum(char *s)//返回字符串s对应的整数
 {
 	long long int d=0;
 	for(int i=0;s[i];i++)
 	   d=d*10+s[i]-'0';
 	   return d;
 } 
 
 Vector ADD(Vector m1,Vector m2)//两个向量进行+操作，m1+m2 
 {
 	if(m1.cnt==-1) m1=var[m1.data[0]];
	if(m2.cnt==-1) m2=var[m2.data[0]];
	Vector tmp;
	if(m1.cnt==1)// 操作数m1为单个数
	{ 
		tmp=m2;
		for(int i=0;i<m2.cnt;i++)
		  tmp.data[i]+=m1.data[0];
	 } 
	 else if(m2.cnt==1)//操作数m2为单个数
	 {
	 	tmp=m1;
		for(int i=0;i<m1.cnt;i++)
		  tmp.data[i]+=m2.data[0];
	  } 
	  return tmp;
 } 
 
 Vector SUB(Vector m1,Vector m2)//两个向量进行-操作，m1-m2 
 {
 	if(m1.cnt==-1) m1=var[m1.data[0]];
	if(m2.cnt==-1) m2=var[m2.data[0]];
	Vector tmp;
	if(m1.cnt==1)// 操作数m1为单个数
	{ 
		tmp=m2;
		for(int i=0;i<m2.cnt;i++)
		  tmp.data[i]=m1.data[0]-tmp.data[i];
	 } 
	 else if(m2.cnt==1)//操作数m2为单个数
	 {
	 	tmp=m1;
		for(int i=0;i<m1.cnt;i++)
		  tmp.data[i]-=m2.data[0];
	  } 
	  return tmp;
 } 
 
 Vector MUL(Vector m1,Vector m2)//两个向量进行*操作，m1*	m2 
 {
 	if(m1.cnt==-1) m1=var[m1.data[0]];
	if(m2.cnt==-1) m2=var[m2.data[0]];
	Vector tmp;
	if(m1.cnt==1)// 操作数m1为单个数
	{ 
		tmp=m2;
		for(int i=0;i<m2.cnt;i++)
		  tmp.data[i]*=m1.data[0];
	 } 
	 else if(m2.cnt==1)//操作数m2为单个数
	 {
	 	tmp=m1;
		for(int i=0;i<m1.cnt;i++)
		  tmp.data[i]*=m2.data[0];
	  } 
	  return tmp;
}
 
 Vector compADD(Vector m1)//进行+/操作：+/m1
 {
	int ID;
 	if(m1.cnt==-1){ID=m1.data[0];m1=var[m1.data[0]];}
 	Vector tmp=m1;
 	tmp.cnt=1;
 	long long int d=0;
 	for(int i=0;i<m1.cnt;i++)
 	{
 		d+=m1.data[i];
	 }
	 tmp.data[0]=d;
	 var[ID]=tmp;
	 return tmp;
 }
 
 Vector compSUB(Vector m1)//进行-/操作：-/m1
 {
 	int ID;
 	if(m1.cnt==-1){ID=m1.data[0];m1=var[m1.data[0]];}
 	Vector tmp=m1;
 	tmp.cnt=1;
 	long long int d=0;
 	for(int i=m1.cnt-1;i>=0;i--)
 	{
 		d=m1.data[i]-d;
	 }
	 tmp.data[0]=d;
	 var[ID]=tmp;
	 return tmp;
}
 
 Vector compMUL(Vector m1)//进行*/操作：*/m1
  {
  	int ID;
  	if(m1.cnt==-1) {ID=m1.data[0];m1=var[m1.data[0]];}
  	Vector tmp=m1;
  	tmp.cnt=1;
  	long long int d=1;
  	for(int i=0;i<m1.cnt;i++)
  	{
  		d*=m1.data[i];
	}
	tmp.data[0]=d;
	var[ID]=tmp;
	return tmp;
   } 