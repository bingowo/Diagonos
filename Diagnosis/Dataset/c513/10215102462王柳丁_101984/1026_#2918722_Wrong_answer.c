#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b)
{

    int *a1=(int *)a;
    int *b1=(int *)b;
    return ((*a1>*b1)?1:-1);
}

int main() {
	int i;
	long long int n,res=0;
	scanf("%lld",&n);
	char num[100];//读入每个数
	long long int nums[n];//存放
	for(i=0;i<n;i++)
	{
		scanf("%s",num);
		int j;
		nums[i]=0;
		for(j=0;j<strlen(num);j++)
		{
			nums[i]=nums[i]*10+num[j]-'0';
		}
	}
	qsort(nums,n,sizeof(nums[0]),cmp);
	for(i=0;i<n/2;i++)
    {
        res=abs(nums[2*i]-nums[2*i+1])+res;
    }
	/*for(i=0;i<n;i++)
	{
		printf("%lld ",nums[i]);
	}*/
	printf("%lld",res);

	return 0;
}
