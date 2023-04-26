#include<stdio.h>
#include<string.h>
int main()
{
	char s[1000];
	int a[1000]={0},b[1000]={0},c[1000]={0};
	int f[100]={0},z=0;
	scanf("%s",s);
	printf("0001");
	int len=strlen(s);
	int t=len,j=1;
	while(t>0)//数字个数转成二进制(10位) 
	{
	    a[j]=t%2;
		t=t/2;
		j++;	
	}
	for(int i=0;i<10-j;i++)
	{
		printf("0");
	}
	while(j>0)
	{
		printf("%d",a[j]);
		j--;
	}
	int e=len/3;//3个一组的个数 
	int d=len%3;//末尾的个数
	int temp=0,h=0,m=0,j1=0,i1=1;
	if(e==0)//len<3
	{
		    if(len==1)//1位数字4位二进制 
		    {
			temp=s[0]-'0';
			while(temp>0)
			{
				b[i1]=temp%2;
				temp=temp/2;
				i1++;
			}
			for(j1=0;j1<4-i1;j1++)
			{
				printf("0");
			}
			while(i1>0)
			{
				printf("%d",b[i1]);
				i1--;
			}
		}
		if(len==2)//2位数字7位二进制 
		{
			temp=(s[0]-'0')*10+(s[1]-'0');
			while(temp>0)
			{
				b[i1]=temp%2;
				temp=temp/2;
				i1++;
			}
			for(j1=0;j1<7-i1;j1++)printf("0");
			while(i1>0)
			{
				printf("%d",b[i1]);
				i1--;
			}
		}
	}
	else{
		for(i1=0;i1<e;i1++)
		{
			m=0;
			temp=(s[j1]-'0')*100+((s[j1+1]-'0')*10)+(s[j1+2]-'0');
			//f[z]=temp;
			//z++;
			j1=j1+3;
			while(temp>0)
			{
				c[m]=temp%2;
				temp=temp/2;
				m++;
			}
			//printf(" %d ",m);
			for(int n=0;n<10-m;n++)printf("0");//3位数字，10位2进制 
			int q=m-1;
			while(q>=0)
			{
				printf("%d",c[q]);
				q--;
			}
		}
	    if(d==1)
		    {
		    i1=0;
			temp=s[j1]-'0';
			while(temp>0)
			{
				b[i1]=temp%2;
				temp=temp/2;
				i1++;
			}
			for(j1=0;j1<4-i1;j1++)
			{
				printf("0");
			}
			while(i1>0)
			{
				printf("%d",b[i1]);
				i1--;
			}
		}
		if(d==2)
		{
			i1=0;
			temp=(s[j1]-'0')*10+(s[j1+1]-'0');
			while(temp>0)
			{
				b[i1]=temp%2;
				temp=temp/2;
				i1++;
			}
			for(j1=0;j1<7-i1;j1++)printf("0");
			int i2=i1-1;
			while(i2>=0)
			{
				printf("%d",b[i2]);
				i2--;
			}
		}
		printf("\n");
		//for(int y=0;y<z;y++)printf("%d ",f[y]);
	}
}