#include<stdio.h>
int main()
{
    int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		int c=a^b;
		int check=1,num=0;//num用来记录1的个数 
		for(int j=0;j<32;j++)
		{
			if(c&check) num++;
			check=check<<1; 
		}
		printf("%d\n",num);
	}
	return 0;
}