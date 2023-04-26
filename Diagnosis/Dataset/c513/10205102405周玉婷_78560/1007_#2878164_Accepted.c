#include<stdio.h>
#include<string.h>
void itob(int n,char s[35])//直接跳过前置0；并且完成了转换成二进制形式 
{
	int i=34-1;
    do{
    	s[i--]=(n%2==1)?'1':'0';
	}	
	while(n=n/2);
	memmove(s,s+i+1,35-i-1);
	s[35-i-1-1]=0;//printf("\n%d\n",i);
}
int main()
{
	int t;
	scanf("%d",&t);
	int i=0;
	while(t--)
	{
		int n;
		scanf("%d",&n);
		char s[35];
		itob(n,s);
		char *p1=s,*p2=s;
		int maxlen=1,len=0;//maxlen储存最大值，len,用于暂存长度
		while(*p2)
		{
			p2++;
			if(*(p2-1)==*p2)
			{len=p2-p1;//p2比最后一个字符大一，这样p2-p1为字符长度   oi
			maxlen=(len>maxlen)?len:maxlen; 
			p1=p2;
			}
		}   
		len=p2-p1;//printf("%d",len);
		maxlen=(len>maxlen)?len:maxlen;
		printf("case #%d:\n%d\n",i++,maxlen);	      
	}
	return 0;
 } 