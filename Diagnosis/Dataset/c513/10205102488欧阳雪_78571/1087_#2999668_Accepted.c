#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int Add1(char A[],int k)
{
	int i=k;
	while(i>=0)
	{
		A[i]+=1;
		if(A[i]<='9'){
			return i;
		}
		else{
			A[i]='0';//进一位变为0 
			i--;
		}
	}
	return i; 
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++)
	{
		char A[200]={'0'};//不能直接是 ={0}！！！ 
		scanf("%s",A+1);//保留A[0]存放进位！！！ 
		int len=strlen(A);
		//printf("len:%d\n",len);
		int i,j;
		Add1(A,len-1);
	//	printf("test:%s\n",A+1);
		
		for(i=1;i<len;i++)//找到最高位的重复位的位置 
		{
			if(A[i]==A[i-1])
			{
				break;
			}
		}
		if(i!=len)
		{
			i=Add1(A,i);//给重复位加1 
			while(i>0)//判断加1后会不会和前一位形成重复位 
			{
				if(A[i]!=A[i-1])//只需判断前一位，因为已经是重复中的最高位 
				{
					break;
				}
				else i=Add1(A,i);//一直加到不是重复数为止 
			}
			for(j=i+1;j<len;j++)
			{
				A[j]=(j-i+1)%2+'0';//给修改后的位置后面填充0101使其最小 
			}
		}
		printf("case #%d:\n",t);
		if(A[0]!='0'){//最高位有进位 
			printf("%c",A[0]);
		}
		printf("%s\n",A+1);
	}
}