#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Rto10(char a[], int r)
{
	int len, i, num;
	int sum = 0;
	len = strlen(a);
	for (i = 0; i < len; i++)
	{
		if (a[i] != '-')
			num = a[i] - '0';
		else if (a[i] == '-')
			num = -1;
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
        int ans=Rto10(a,3);
        printf("case #%d:\n%d\n",i,ans);
    }
    return 0;
}
