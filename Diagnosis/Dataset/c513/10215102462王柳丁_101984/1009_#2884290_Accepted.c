#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int GCD(int m,int n)
{
    int max,min;
    if(m<n){min=m,max=n;}
    else{min=n,max=m;}
    int res;
    res=max%min,max=min,min=res;
    int out=1;
    out=(res==0)?max:GCD(min,max);
    return out;
}
int main()
{
	int N,i;
	scanf("%d",&N);
	int num,len,k,count;
	getchar();
	for(i=0;i<N;i++)
	{
		char a;
		num=0,len=0;
		//while(getchar()=='\n');
		while((a=getchar())!='\n')
		{
			//printf("(a=%c)\n",a);
			int eve=a;
			for(count=0;count<8;count++)
			{
				if((eve&(1<<count))==(1<<count))num++;
			}
			//printf("(%d)\n",num);
			len=len+8;
			//printf("(%d)\n",len);
		}
		
		k=GCD(len,num);
		num/=k;
		len/=k;
		printf("%d/%d\n",num,len);
	}
	return 0;
}