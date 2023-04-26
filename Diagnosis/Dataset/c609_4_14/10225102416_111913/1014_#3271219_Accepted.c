#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

int main()
{
	long long a,b;
	scanf("%lld %lld",&a,&b);
    
	int s[100]={0};
    int i=99;
	int pos=0;   //记录小数点位数   99-pos为整数部分最后一个数的指标
    
    while(b/=3)
    {
        pos++;
    }
    
	do{
		s[i--]=a%3;
	} while(a/=3);         //储存普通三进制
	
	if(i>99-pos)   //整数部分为0,人为移动
	{
		i=99-pos;
	}
		
	int flag=0;
	for(int j=99;j>i;j--)  //考虑可能进一位 预留s[i]
    {
        if(s[j]+flag+1>=3)
        {
            s[j]=s[j]+flag-2;
            flag=1;
        }
        else{
            s[j]=s[j]+flag+1;
            flag=0;
        }
    }
    s[i]=flag;
	
    for(int j=99;j>i;j--)  
    {
        s[j]=(s[j]-1==-1)?2:s[j]-1;
    }
    
    int j=i;
    int count=0;      //统计小数部分末尾0的个数 
    
    for(int k=99;k>99-pos;k--)    //小数部分
    {
    	if(s[k]!=0)
    	{
    		break;
		}
		count++;
	}
    
    while(s[j]==0&&j<99-pos)       //整数部分去除前缀0  s[99-pos]=0时正常输出0即可
    {
    	j++;
	}
	
	while(j<100-count)
	{
	    printf("%d",s[j]);
		if(j==99-pos&&pos!=0&&count!=pos)   //小数部分不全为0,且小数部分长度不为0
		{
		    printf(".");
		}
		j++; 
	} 

	return 0;
} 
