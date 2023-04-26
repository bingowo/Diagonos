#include <stdio.h>
int main()
{   
    int num=0;
    scanf("%d",&num);
    for(int n=0;n<num;n++){
        printf("case #%d:",num);
        printf("\n");
    
	int a = 0;
	int b = 0;
	while (scanf("%d%d", &a, &b) != EOF)
	{
		int count = 0;
		while (a)
		{
			count = count + a%b;
			a = a / b;
		}
		//count算完是各项位数之和
		int arr[32] = { 0 };//数组是为了转换b进制
		int i = 0;
		while (count)
		{//打印count转换b进制后的每一位，放入数组之中
			arr[i] = count % b;
			i++;
			count = count / b;//通过百分号加除号的方式剥离
		}
		while (--i <= 0)//每进一次循环之前i减去1
		{
			if (arr[i] < 10)//十进制以内
			{
				printf("%d", arr[i]);
			}
			else//十六进制
			{
				printf("%c", arr[i] - 10 + 'A');
			}
		}
	}}
	return 0;
}
