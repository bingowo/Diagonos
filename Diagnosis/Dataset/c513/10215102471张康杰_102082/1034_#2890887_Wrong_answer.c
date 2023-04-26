#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//函数间的通信如何实现
static double alphabet[26];
int cmp(const void*a,const void*b)
{
    if(toupper(*(char*)a) == *(char*)b)
        return -1;
    else if(*(char*)a == toupper(*(char*)b))
        return 1;
    else
        return alphabet[toupper(*(char*)b) - 'A'] - alphabet[toupper(*(char*)a) - 'A'];
        //toupper这个函数不会改变原始输入的大小写吗？？？？？？？

}

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        for(int j = 0;j < 26;j++)
        {
            scanf("%lf",&alphabet[j]);
        }

        char input[101];
        scanf("%s",input);
        qsort(input,strlen(input),sizeof(char),cmp);
        printf("case #%d:\n%s\n",i,input);

    }
    return 0;
}
