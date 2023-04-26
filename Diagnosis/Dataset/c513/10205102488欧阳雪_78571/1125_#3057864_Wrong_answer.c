#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
long long int result(long long int m,long long int n){//计算最简分数 （m为分母）
	long long int a = m;
    long long int b = n;
    while(a % b)
    {
        long long int temp = a % b;
        a = b;
        b = temp;
    }
    m /= b;
    n /= b;						
   	printf("%lld",n);
   	printf("/");
   	printf("%lld\n",m);
}
int main()
{
	int T;
	scanf("%d",&T);
	int i=0;
	for(i=0;i<T;i++)
	{
		char xs[20]={0};
		scanf("%s",xs);
		long long int zs[20]={0};//存整数 
		long long int xxs=0;//存小数部分 
		long long int fz=0,fm=0;
		int d=0,k=0;//小数点和括号的位置 
		int t=0,j=0,len=0;
		long long z=0;//z整数
		for(t=0;t<strlen(xs);t++) 
		{
			if(xs[t]=='.')//找'.' 
			{
				d=t;
			}
			if(xs[t]=='[')//找'['
			{
				k=t;
				break;
			}
		}
		int test[20]={0},q=0;
		for(t=0;t<strlen(xs);t++)
		{
			if(xs[t]!='.')
			{
				test[q++]=(xs[t]-'0');
			}
		}
	//	printf("d,k:%d %d\n",d,k);
		if(k==0)//普通小数1.5
		{
			//处理整数部分 
			z=0;
			for(t=0;t<d;t++)
			{
				z*=10;
				z=z+(xs[t]-'0');
		    }
		    //处理小数部分 
		    len=0;
		    for(t=d+1;t<strlen(xs);t++)
		    {
		    	xxs*=10;
		    	xxs+=(xs[t]-'0');
		    	len++;
			}
			fz=z*pow(10,len)+xxs;
			fm=pow(10,len);
			printf("case #%d:\n",i);
			result(fm,fz);

		}
		else//无限循环小数 
		{
			t=k+1;
			int len1=0;//循环节的位数 
			long long  xhj=0;//循环节 
			while(xs[t]!=']'&&xs[t]!='\0')
			{
				len1++;
				xhj*=10;
				xhj+=(xs[t]-'0');
				t++;
			}
			fm=pow(10,len1)-1;
		//	printf("xhj,fm:%d %d\n",xhj,fm);
			if(xs[d+1]!='[')//小数点后含非循环小数 
			{
				j=0;
				for(t=0;t<k;t++)
				{
					if(xs[t]!='.')
					{
						zs[j++]=(xs[t]-'0');
						//printf("%d\n",zs[j-1]);
					}
				}
				z=0;
				for(t=0;t<j;t++)
				{
					z*=10;
					z+=zs[t];
				}
				len=k-d-1;
				//printf("z,len:%d %d\n",z,len);
				fz=z*fm+xhj;
				fm=fm*pow(10,len);
				printf("z:%lld\n",z);
				printf("case #%d:\n",i);
			    result(fm,fz);
			}
			else
			{
				z=0;
				for(t=0;t<d;t++)
				{
					z*=10;
					z+=(xs[t]-'0');
				}
				fz=z*fm+xhj;
				printf("case #%d:\n",i);
			    result(fm,fz);
			}
		}
	}
}