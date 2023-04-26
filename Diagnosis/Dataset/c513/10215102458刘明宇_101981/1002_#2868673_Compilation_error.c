#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int a[123];
    memset(a, -1, sizeof(a));//初始化数组值为01
    scanf("%d", &T); /*输入问题数*/
    int i = 0;
    char info;
    while(i < T)
    {
        scanf("%c", &info);
        int res = 0;
        int nums[61];
        nums[0] = 1;
        int top;
        
        for(int j = 2; j < strlen(info);j++)
        {
            if(info[0] != info[1]) {nums[1] = 0; top = 2}
            else {nums[1] = 1;}
        }
        
        
        printf("case #%d\n", i);
        printf("%d",res);
        i++;
    }
    return 0;