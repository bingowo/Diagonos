#include<stdio.h>

int LCM(int a,int b)
{
		int c = a;//将a赋值给c
		int d = b;//将b赋值给d

		//使a是大的值
		if (a < b)
		{
			int x = a;
			a = b;
			b = x;
		}

		int tmp = b;//tmp存放a和b的最大公约数
		while (a % b)
		{
			tmp = a % b;
			a = b;
			b = tmp;
		}
	return (c*d)/tmp;
}

int gcd(int a,int b)
{
    int c = a%b;
    while(c!=0)
    {
        a = b;
        b = c;
        c = a%b;
    }
    return b;
}

typedef struct num{
    int up;
    int down;
}num;
int main()
{
    int n;
    scanf("%d",&n);
    num*s = (num*)malloc(sizeof(num)*n);
    for(int i = 0;i<n;i++)
    {
        scanf("%d/%d",&((s+i)->up),&((s+i)->down));
    }

    int lcm = 1;
    for(int i=0;i<n;i++)
    {
        lcm = LCM(lcm,(s+i)->down);
    }
    int up_sum = 0;
    for(int i=0;i<n;i++)
    {
        up_sum = up_sum+((s+i)->up)*lcm/((s+i)->down);
    }
    printf("%d/%d",up_sum/gcd(up_sum,lcm),lcm/gcd(up_sum,lcm));






    free(s);
    return 0;
}
