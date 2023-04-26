#include<stdio.h>

int get_diff_bit(int m, int n)
{
	int count = 0;
	int tmp = m ^ n;
	while (tmp)
	{
		tmp = tmp & (tmp - 1);
		count++;
	}
	return count;
}

int main()
{
	int n,i,x,j,y,num;
	scanf("%d",&n);
	for(j=0;j<n;j++){
		scanf("%d %d",&x,&y);
		num = get_diff_bit(x,y);
	}
	printf("%d\n",num);
}