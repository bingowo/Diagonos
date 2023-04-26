#include<stdio.h>

int judge(m)
{
	int ret = 1;
	while (m)
	{
		if (m % 10 != 1 && m % 10 != 0)
		{
			ret = 0;
			break;
		}
		m = m / 10;  //依次检查每一位是不是1和0
      
	}
	

	return ret;
}


int main()
{
	int a;
	int ret, m;
	scanf_s("%d", &a);
	int isfind = 0;
	for (int i = 2; i < 10000; i++) {
		m = i * a;
		ret = judge(m);

		if (ret)
		{
			printf("%d", m);
			isfind = 1;
			break;
		}
	}
	if (!isfind)  printf("-1");
	return 0;
}