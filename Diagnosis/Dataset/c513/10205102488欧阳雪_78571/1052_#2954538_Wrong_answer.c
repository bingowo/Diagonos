#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		char s[21]={0};
		scanf("%s",s);
		int a[10]={0};
		int k=0;
		
    	for(int j=0;j<strlen(s);j++)//0
		{
			if(s[j]=='Z'){
				a[0]++;
			}
		}
		for(int j=0;j<strlen(s);j++)//2
		{
			if(s[j]=='W'){
				a[2]++;
			}
		}
		for(int j2=0;j2<strlen(s);j2++)//4
		{
			if(s[j2]=='U'){
				a[4]++;
			}
		}
		for(int j1=0;j1<strlen(s);j1++)//3
		{
			if(s[j1]=='R'){
				a[3]++;
			}
		}
		a[3]=a[3]-a[0]-a[4];
		for(int j3=0;j3<strlen(s);j3++)//1
		{
			if(s[j3]=='O'){
				a[1]++;
			}
		}
		a[1]=a[1]-a[0]-a[2]-a[4];
		for(int j4=0;j4<strlen(s);j4++)//5
		{
			if(s[j4]=='F'){
				a[5]++;
			}
		}
		a[5]=a[5]-a[4];
		for(int j5=0;j5<strlen(s);j5++)//6
		{
			if(s[j5]=='X'){
				a[6]++;
			}
		}
		for(int j6=0;j6<strlen(s);j6++)//7
		{
			if(s[j6]=='S'){
				a[7]++;
			}
		}
		a[7]=a[7]-a[6];
		for(int j7=0;j7<strlen(s);j7++)//9
		{
			if(s[j7]=='N'){
				a[9]++;
			}
		}
		a[9]=a[9]-a[1]-a[7];
		for(int j8=0;j8<strlen(s);j8++)//8
		{
			if(s[j8]=='G'){
				a[8]++;
			}
		}
		a[8]=a[8]-a[9];
		
		printf("case #%d:\n",i);
		for(int t=0;t<9;t++)
		{
			if(a[t]>0)
			{
				for(int m=0;m<a[t];m++)
				{
					printf("%d",t);
				}
			}
		}
		printf("\n");
	}
}