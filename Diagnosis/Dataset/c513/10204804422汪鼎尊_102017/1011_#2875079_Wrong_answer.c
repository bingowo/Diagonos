#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	long long input;
	int i,j;
	long long real=0,img=0,one=1,rtemp=0,itemp=0;
	
	
	scanf("0x%llx",&input);
	for(i=63;i>=0;i--)
	{
		rtemp=real*(-1)+img*(-1);
		itemp=real+img*(-1);
		real=rtemp;
		img=itemp;
		real+=(input>>i)&one;
		//printf("%lld+%lldi\n",real,img);
	}
	
	
	if(real!=0)printf("%lld",real);
	if(real!=0&&img>0)printf("+");
	if(img!=0&&img!=1)printf("%lldi",img);
	if(img==1)printf("i");
	if(real==0&&img==0)printf("0");
	
	return 0;
}