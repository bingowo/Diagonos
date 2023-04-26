#include <stdio.h>
int gcd1(int x, int y)
{
	int z = x % y;
	while(z)
	{
		x = y;
		y = z;
		z = x % y;
	}
	return y;
}
int main()
{
    int cnt=0;
    char ch;
    scanf("%d%c",&cnt,&ch);
    for(int i=0;i<cnt;i++)
    {
        char s[241];
        gets(s);
        int num1=0,k=0,d=1;
        while(s[i]!='\0') k++;
        int num=8*k;
        char *p = s;
        for(int t=0;t<num;t++)
        {
            if(*p&d) num1++;
            d=d<<1;
        }
        int gcd=gcd1(num1,num);
        num1=num1/gcd;
        num=num/gcd;
        printf("%d/%d\n",num1,num);
    }
    return 0;
}
