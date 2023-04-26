#include<stdio.h>
#include<string.h>
#include<math.h>
int func(char a[],int y)//y进制转换成10进制
{
    int n = strlen(a);//判断字符串的长度函数
    int i,  num = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] == 'A'||'a')
            num += 10 * pow(y, n - i - 1); //pow() 函数用来求 x 的 y 次方的值。
        else if (a[i] == 'B'||a[i]=='b')
            num += 11 * pow(y, n - i - 1);
        else if (a[i] == 'C'||a[i]=='c')
            num += 12 * pow(y, n - i - 1);
        else if (a[i]=='D'||a[i]=='d')
            num += 13 * pow(y, n - i - 1);
        else if (a[i] == 'E'||a[i]=='e')
            num += 14 * pow(y, n - i - 1);
        else if(a[i]=='F'||a[i]=='f')
            num += 15 * pow(y, n - i - 1);
        else
            num+=(a[i]-'0')* pow(y, n - i - 1);
    }
    return num;
}

//函数： 将10进制数字转换为x进制，并将转换后的数字存储在字符串中并输出
void dec2hex(int n,int x)
{
	char str[100];
	int p;
	int i;
	int digit;
	char c;
	p=0;
	do{
		digit=n%x;
		if(digit<10)
		{
			str[p]=digit+'0';
		}else
		{
			str[p]=digit-10+'A';
		}
		p++;
		n=n/x;
	}while(n>0);
	str[p]='\0';
	for(i=0;i<p/2;i++)
	{
		c=str[i];
		str[i]=str[p-1-i];
	    str[p-1-i]=c;
	}
	printf("%s",str);
}

void main()
{
    char a[10];
    int x,y;
    //printf("请输入y进制和一个y进制的数a和想要转成的进制x:\n");
    scanf("%d",&y);
    scanf("%s",a);//gets从标准输入设备读字符串函数。可以无限读取，不会判断上限，以回车结束读取
    scanf("%d",&x);
    dec2hex(func(a,y),x);

}