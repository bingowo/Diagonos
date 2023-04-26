#include<stdio.h>
#include<string.h> 
long long pow(int a,int b) //不知道为什么15^14用pow函数算出来少了1 
{
	int i;
	long long res=1;
	for(i=0;i<b;i++)
		res*=a;
	return res;
}

int main()
{
  	int t;
	int i,j;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		char str[60];
		scanf("%s",str);
		int len=strlen(str);
		if(len==1)
			printf("case #%d:\n1\n",i);
		else
		{
			int table[75];
			for(j=0;j<75;j++)
				table[j]=-1;
			int a=2;
			table[str[0]-'0']=1;//table[str[len-1]-'0']=1;
			//如：输入100 实际上1是最低位str[0] 
			for(j=1;j<len;j++)//第二个字符设为0，注意不是字符串的第二个 
			{
				if(str[j]!=str[0])
				{
					table[str[j]-'0']=0;
					break;	
				}	
			}
			if(table[str[1]-'0']==-1)//if(table[str[len-2]-'0']==-1)
				table[str[1]-'0']=0;//table[str[len-2]-'0']=0;
			for(j=2;j<len;j++)//for(j=len-3;j>=0;j--)
			{
				if(table[str[j]-'0']==-1)
					table[str[j]-'0']=a++;
			}
			long long res=0;
			int k=len-1;
			for(j=0;j<len;j++)
				res+=(table[str[k--]-'0'])*(pow(a,j));	
			printf("case #%d:\n%lld\n",i,res);
		}
	}
	return 0;
}