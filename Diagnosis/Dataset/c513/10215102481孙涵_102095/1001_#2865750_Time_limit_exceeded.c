#include <stdio.h>
#include <stdlib.h>
int main()
{
	int num_10,R,num_R,num_T,num_N;
	scanf("%d",&num_T);
	while (num_T>=0)
	{
		scanf("%d%d",&num_10,&R);
		int sign;
		if (num_10<0)
		{
			sign=-1;
		}
		else
		{
			sign=1;
		}
		int arr[33];
		int counter=0;
		while (num_10>=0)
		{
			arr[counter]=num_10-num_10/R;
			counter=counter+1;
		}
		counter=counter-1;
		while (counter>=0)
		{
			printf("%d",arr[counter]);
			counter=counter-1;
		}
		printf("\n");
		num_T=num_T-1;
	}
	return 0;
}