#include <stdio.h>
#include <string.h>
const int MAXN=1e3+55;
char Octal[55],decimal[155];
int T;
int main()
{
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		scanf("%s",Octal);
		int num=0,digit,temp;
		int len=strlen(Octal)-1,j;
		for (; len != 1; --len) 
		{
		    digit = Octal[len]-'0';
		    j = 0;
		    do 
			{
		        if (j < num)
		            temp = digit*10 + decimal[j]-'0';
		        else
		            temp = digit*10;
		        decimal[j++] = temp/8 +'0';
		        digit = temp%8;
		    } while (digit!=0 || j < num);
		    num = j;
		}
		decimal[num] ='\0';
		printf("case #%d:\n",i);
		printf("0.%s",decimal);
	}
	return 0;
}