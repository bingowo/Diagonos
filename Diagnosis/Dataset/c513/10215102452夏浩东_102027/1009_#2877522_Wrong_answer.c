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
        char s[121];
        gets(s);
        int num1=0,i=0;
        for(i=0;s[i]!='\0';i++)
        {
            char *p = NULL;
            p=&s[i];
            int d=1;
            for(int t=0;t<sizeof(char);t++)
            {
                if(*p&d) num1++;
                d=d<<1;
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
