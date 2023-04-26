#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
	int c=*(int*)a;
	int d=*(int*)b;
	if(c>d){
		return 1;
	}
	else{
		return -1;
	}
}
int GCD(int x, int y)
{
	//判断x/y余数是否为0
	int z = x % y;

	//直到余数为0，则跳出循环
	while(z)
	{
		//循环过程中，将除数给x，余数给y，求新的余数z
		x = y;
		y = z;
		z = x % y;
	}
	//除数y为最大公约数
	return y;
}

int main()
{
	int len,sum;
	scanf("%d%d",&len,&sum);
	int H[1002]={0};//高度数组,记录每个点的高度 
	for(int i=1;i<=len;i++)
	{
		scanf("%d",&H[i]);
	}
	qsort(H,len+1,sizeof(H[0]),cmp);//对高度升序排序
	/*for(int l=1;l<=len;l++)
	{
		printf("%d ",H[l]);
	}
	printf("\n");*/
	
	int X1[1002]={0},X2[1002]={0};//X1存边界高度值，X2存边界下标 
	int f=1,z=0,flg=1;
	while(f<=len)
	{
		while(H[f]==H[f+1]&&(f+1)<=len)
		{
			f++;
			flg++;//用于判断是否高度全一样 
		}
		if(flg==len)
		{
			break;
		}
		X1[z]=H[f];//printf("X1:%d %d\n",z,X1[z]);
		X2[z]=f;//printf("X2:%d %d\n",z,X2[z]);
		z++;
		f++;
	}

	
	int j1=0,flg2=0;
	int high=0,high_fz=0,high_fm=0;
	while(sum)
	{
		if(flg==len)//高度全一样 
		{
			high_fz=sum;
			high_fm=len;
			high=H[len];
		//	printf("high_fz:%d\n",high_fz);
			break;
		}
		
		int s1=X2[j1]*(X1[j1+1]-X1[j1]);
		high=X1[j1]; 
	//	printf("s1:%d %d\n",j1,s1);
		if(sum<s1)
		{
			high_fz=sum;
			high_fm=X2[j1];
			break;
		} 
		else{
			sum-=s1;
		//	printf("sum:%d %d\n",sum,s1);
			high=X1[j1+1];
			j1++;
		}
		if(j1>=z&&sum>0)
		{
			flg2=1;
			break;
		}
		
	}
	
   if(flg2==1&&flg!=len)//全满 
    {
    	while(sum>=len)
		{
			high+=sum/len;
			sum=sum%len;
			high_fz=sum%len;
			high_fm=len;
		}
		if(high>0)
		{
			printf("%d",high);
		}
		if(high_fz>0&&high_fm>0)
        {
        	if(high>0)
        	{
        		printf("+");
			}
        	
        	high_fz/=GCD(high_fz,high_fm);
		    high_fm/=GCD(high_fz,high_fm);
		
			printf("%d",high_fz);
		    printf("/");
		    printf("%d",high_fm);
	
		}
		return 0;
	}

	
	if(high_fz>0&&high_fm>0)
	{
		
	//	printf("fz fm:%d %d\n",high_fz,high_fm);
		if(high_fz>=high_fm)
		{
			high+=high_fz/high_fm;
			high_fz=high_fz%high_fm; 
		}
		if(high>0)
	{
		printf("%d",high);
	}
        if(high_fz>0&&high_fm>0)
        {
        	if(high>0)
        	{
        		printf("+");
			}
        	
        	high_fz/=GCD(high_fz,high_fm);
		    high_fm/=GCD(high_fz,high_fm);
		
			printf("%d",high_fz);
		    printf("/");
		    printf("%d",high_fm);
	
		}

	}
	else{
		printf("%d",high);
	}
}