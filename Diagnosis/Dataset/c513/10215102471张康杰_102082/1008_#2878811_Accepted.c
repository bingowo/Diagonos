#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        unsigned int input1,input2,same = 0,j;
        scanf("%u %u",&input1, &input2);
        for(j = 0;j < 32;j++)
        {
            if(((input1>>j)&1) != ((input2>>j)&1))//当条件为真时并没有进入if语句？？？？？？？
                //回答：优先级的问题，(input1>>j)&1 != (input2>>j)&1中，位运算符优先级低于比较运算符
                same++;

        }
        printf("%d\n",same);
    }

    return 0;
}
