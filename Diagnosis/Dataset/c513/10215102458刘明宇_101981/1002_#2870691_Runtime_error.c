#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main()
{
    int a[123];
    memset(a, -1, sizeof(a));//初始化数组值为01
    int T;
    scanf("%d", &T); /*输入问题数*/
    int i = 0;
    char info;
    while(i < T)
    {
        scanf("%c", &info);//输入秘密信息
        int res = 2;//统计进制数，即不同的元素有多少个
        int nums[61];//储存进制数，元素数为秘密信息长度
        nums[0] = 1;
        nums[1] = 0;//第一个一定是1
        a['info[0]'] = 1;//同时要改变a中对应位置的值
        a['info[1]'] = 0;//通常情况下第二个元素和第一个不同
        int top = 2;//初始基数为2
        for(int j = 2; j < strlen(info);j++)
        {
            if(a['info[j]'] != -1)//如果这个字母之前没有出现过
            {
                a['info[j]'] = top;//先改变A中的竖直，便于查重
                nums[j] = top;//再改变进制表中的数
                top++;//top值要增加
                res++;
            }
            else //如果出现过
            {
                nums[j] = a['info[j]'];//就把a中对应的值摘出来
            }
        }
        int sum = 0;
        int x = 1;
        for(int m = 1;m < top;m++)
        {
            x = x * top;
        }
        //x是最高位的要乘的数
        for(int k = 0; k < strlen(info); k++)
        {
            sum += nums[k] * x;
            x  = x / top;
        }
        printf("case #%d\n", i);
        printf("%d",sum);
        i++;
    }
    return 0;
}