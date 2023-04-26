#include<stdio.h>
#include<string.h>
const int N=1005;
int main(){
	char str[N],dest[N];
	memset(dest,0,sizeof(dest));
	int T,m=0;
	scanf("%d",&T);
	for(m=0;m<T;m++)
	{
		scanf("%s",str);
		int i=0,k=0,tem,num;
		int len=strlen(str)-1;
		for(;len>1;len--)
		{
			int num=str[len]-'0';
			for(;i<k||num!=0;i++)
			{
				tem=10*num+(i<k?dest[i]-'0':0);
				dest[i]=tem/8+'0';
				num=tem%8;
			}
			k=i;
		}
	}
	printf("case #%d:\n0.%s\n",m,dest);
	
}