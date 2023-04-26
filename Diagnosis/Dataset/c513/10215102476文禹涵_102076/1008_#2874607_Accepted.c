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
	int n,x,y;
	scanf("%d",&n);
    while (n--){
    	scanf("%d%d",&x,&y);
    	printf("%d\n", get_diff_bit(x,y)); 
    }
}


	
