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
        int num1=0,i=0;
        for(i=0;s[i]!='\0';i++)
        {
            short int k =(short int)s[i];
            while(k!=0)
            {
                ++num1;
                k=k&(k-1);                  
            }
        }
        int num=8*i;
        int gcd=gcd1(num1,num);
        num1=num1/gcd;
        num=num/gcd;
        printf("%d/%d\n",num1,num);
    }
    return 0;
}