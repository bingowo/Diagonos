#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int flag = 0,flag1 = 0,longest = 0,current = 0;
    //这里设置两个标签,flag表示读到首0,而flag1表示开始记录数字
    char ch;

    //输入，逐个读取
    while((ch = getchar()) != '\n')
    {
        if(isdigit(ch) && !flag && ch != '0' && !flag1)
        {
            flag1 = 1;
            current++;
        }
        //else if(ch == '0' && !flag1)
        //{
        //    continue;
        //}
        else if(isalpha(ch))
        {
            flag1 = 0;
            if(current > longest)
            {
                longest = current;
            }
            current = 0;
        }
        else if(flag1)
        {
            current++;
        }
        
    }
    if(current > longest)
    {
        longest = current;
    }
    printf("%d",longest);
    return 0;

}