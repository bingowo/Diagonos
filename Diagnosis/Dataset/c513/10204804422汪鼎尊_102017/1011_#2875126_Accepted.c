#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int t(char c)
{
	return c>'9'?c+10-'A':c-'0';
}

int main()
{
	char input[50];
	int i,j;
	long long real=0,img=0,rtemp=0,itemp=0;
	
	
	scanf("%s",&input);
	for(i=2;input[i]!='\0';i++)for(j=3;j>=0;j--)
	{
		rtemp=real*(-1)+img*(-1);
		itemp=real+img*(-1);
		real=rtemp;
		img=itemp;
		real=real+((t(input[i])>>j)&1);
		//printf("%lld+%lldi\n",real,img);
	}
	
	
	if(real!=0)printf("%lld",real);
	if(real!=0&&img>0)printf("+");
	if(img!=0&&img!=1&&img!=-1)printf("%lldi",img);
	if(img==1)printf("i");
	if(img==-1)printf("-i");
	if(real==0&&img==0)printf("0");
	
	return 0;
}