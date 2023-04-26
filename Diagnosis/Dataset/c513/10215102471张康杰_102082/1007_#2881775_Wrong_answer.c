#include <stdio.h>
#include <stdlib.h>
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int longest = 1,longest_cur = 1;
        int j = 0;
        char binary[33];//Q:此处开的字符数组中为什么都是\000
        unsigned int input;
        scanf("%u",&input);
        while(input != 0)
        {
            binary[j] = (input&1) + '0';
            j++;//注意区分字符'0',与数字0,加号优先级高于位运算符！！！！！！！！！！！！！！！！！
            input = input>>1;//最开始这里是input = input>>j,如果是j的话右移的位数就会更多导致错误
        }
        binary[j] = '\0';
        char*pt1,*pt2;
        pt1 = binary;
        pt2 = pt1+1;
        while(*pt2)
        {
            if(*pt1 != *pt2)
                longest_cur++;
            else
            {
                if(longest_cur > longest)
                {
                    longest = longest_cur;
                    longest_cur = 0;
                }
                else
                    longest_cur = 0;
            }
            pt1++;
            pt2++;
        }
        if(longest_cur > longest)
            longest = longest_cur;
        printf("case #%d:\n%d\n",i,longest);

    }
    return 0;
}
