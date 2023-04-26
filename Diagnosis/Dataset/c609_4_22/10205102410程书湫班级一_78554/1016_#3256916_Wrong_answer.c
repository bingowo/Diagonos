#include <stdio.h>

char *p;

int get_num(){
	int flag=1;
	int num=0;
	if((*p)=='-'){flag=-1;p++;}
	if((*p)=='+'){p++;}// i前面有可能是+号，注意略过
	
	//仔细考虑终止条件
	while(((*p)!='+')&&((*p)!='-')&&((*p)!='\0')&&((*p)!='i'))
	{
		num=num*10+((*p)-'0');
		p++;
	}
	
	//注意+i或-i可以没有数字。如果它会给-0i这种数据,还需要更详细的处理
	if(num==0 && *p=='i') num=1;	
	
	return flag*num;
}

int main()
{
	char s[100];
	scanf("%s",s);
	p=s;
	long long a=0,b=0;
	int flag1=0,flag2=0;
	
	b=get_num();
	if(*p!='i'){
		a=b;
		b=get_num();
	}

//	printf("%d %di\n",a,b);
	
	int r[100];
	int qr,qi,j=0;
	while(a!=0 || b!=0)//b不为0也可以继续算
	{	
		if(((a+b)%2)==0) r[j]=0;//-1%2==-1
		else r[j]=1;
		qr=(r[j]-a+b)/2;
		qi=(r[j]-a-b)/2;
		a=qr;
		b=qi;
//		printf("%d %di %d\n",a,b,r[j]);
		j++;
	}
	for(int m=j-1;m>=0;m--)//总共j位，所以从j-1开始
		printf("%d",r[m]);
	return 0;
}