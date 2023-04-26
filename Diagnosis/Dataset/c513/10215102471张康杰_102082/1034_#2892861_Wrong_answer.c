#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//函数间的通信如何实现
static double alphabet[26];
//typedef struct{
//    char letter;
//    double frequency;
//};
int cmp(const void*a,const void*b)
{
//    if(toupper(*(char*)a) == *(char*)b)
//        return -1;
//    else if(*(char*)a == toupper(*(char*)b))
//        return 1;
//    else if(alphabet[toupper(*(char*)b) - 'A'] != alphabet[toupper(*(char*)a) - 'A'])
//        return alphabet[toupper(*(char*)b) - 'A'] - alphabet[toupper(*(char*)a) - 'A'];
//    else
//        return *(char*)a - *(char*)b;
//toupper这个函数不会改变原始输入的大小写吗？？？？？？？
    if(alphabet[toupper(*(char*)b) - 'A'] != alphabet[toupper(*(char*)a) - 'A'])
        return alphabet[toupper(*(char*)b) - 'A'] - alphabet[toupper(*(char*)a) - 'A'];
    else
    {
        if(toupper(*(char*)a) == toupper(*(char*)b))
            return *(char*)b - *(char*)a;
    }

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
