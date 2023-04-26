#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//函数间的通信如何实现
static double alphabet[256];

int cmp(const void*a,const void*b)
{
    if(alphabet[*(char*)a] != alphabet[*(char*)b])
        return alphabet[*(char*)b] - alphabet[*(char*)a];
    else
    {
        if(*(char*)a - 32 == *(char*)b)
            return -1;
        else if(*(char*)b - 32 == *(char*)a)
            return 1;
        else
            return *(char*)a - *(char*)b;
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
            scanf("%lf",&alphabet[j + 'A']);
            alphabet[j + 'A' + 32] = alphabet[j + 'A'];
        }

        char input[101];
        scanf("%s",input);
        qsort(input,strlen(input),sizeof(char),cmp);
        printf("case #%d:\n%s\n",i,input);

    }
    return 0;
}
