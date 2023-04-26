#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char s[50] = {'\0'};
    scanf("%s",s);
    int max=0;              //最大个数
    int count = 1;          //此轮计数
    int i = 1;              //数组s[]的计数器
    char flag = s[0];       //前一个字符
    while(i < strlen(s))
    {
        if(flag != s[i])
        {
            count++;
            flag = s[i];
        }
        else{
            if(max<count)
            {
                max = count;
            }
            count = 1;
            flag = s[i];
        }
        i++;
    }
    printf("%d",max);

    return 0;
}
