#include <stdio.h>

int main()
{
	int t,x,p;
    scanf("%d", &t);
    int i;
    for(i = 0; i < t; i++)
	{
        scanf("%d",&x);
        scanf("%d",&p);
        if (x < 0)
		{
            printf("-");
            x = -x;
        }
        int a[100];
        int count = 0;
        do
		{
            a[count++]=x%p;
            x=x/p;
        }
		while(x!=0);
        char temp;
        int i = 0;
        for(i=count-1;i>=0;i--)
		{
            if(a[i] > 9)
			{
                temp = 'A' + a[i] - 10;
            }
            else
			{
                temp = '0' + a[i];
            }
            printf("%c",temp);
        }
        printf("\n");
    }
    return 0;
}