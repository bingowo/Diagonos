#include<stdio.h>
void TenToK(long long int num)
{
    int  c, i = 0;
    long long m;
    int k = 2333;//8杩涘埗绫讳技
    int a[32];
    m = num;
    while (num>0)
    {
        c = (num % k);
        a[i] = c;
        num = num / k;
        i++;
    }
    for (i--; i >= 0; i--)           //灏嗘暟缁勫€掑簭杈撳嚭
        printf("%d ", a[i]);
    printf("\n");
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		long long int num;
		scanf("%lld",&num);
		TenToK(num);
	}
	return 0;
}