#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int _3to10(char a[],int r)
{
    int len, i, num;
	int sum = 0;
	len = strlen(a);
	for (i = 0; i < len; i++)
	{
		if (a[i] =='-')
			num = -1;
		else
			num = a[i] - '0';
		sum = sum * r + num;
	}
	return sum;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char a[100];
        scanf("%s",a);
        printf("case #%d:\n%d\n",i,_3to10(a,3));
    }
    return 0;
}
