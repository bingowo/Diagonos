#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int x,y;
    scanf("%d",&x);
	char number[100];
	int i=0;
	do{
		if(x%-2>=0)   //余数大于0,正常操作
		{
			if(x%-2<10)
			{
				number[i]=x%-2+'0';
			}
			else
			{
				number[i]=x%-2+'A'-10;
			}
			x=x/-2;
		}
		else   //余数小于0,借位操作
		{
			if(x-（-2）*(x/-2+1)<10)    //  x/y+1 也就是 p+1, x-y*p(x/y+1)=R+r
			{
				number[i]=x-（-2）*(x/-2+1)+'0';
			}
			else
			{
				number[i]=x-（-2）*(x/-2+1)+'A'-10;
			}
			x=x/-2+1;
		}
		i++;
	}while(x!=0);   //结束条件为x=0
	
	for(int j=strlen(number)-1;j>=0;j--)  //逆向输出
	{
		printf("%c",number[j]);
	}
	
	return 0;
}
