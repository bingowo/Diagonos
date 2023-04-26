#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int cmpA(const void*a,const void*b)
{
    return *(int*)a - *(int*)b;
}
int cmpB(const void*a,const void*b)
{
    return *(int*)b - *(int*)a;
}
int main()
{
    char ch = getchar();
    int table[1001];
    int input[100],count = 0;
    memset(table,-1,sizeof(int)*1001);
    int n;
    while(scanf("%d",&n) != EOF)
    {
        if(table[n] == -1)
        {
            table[n] = 1;
            input[count] = n;
            count++;
        }
    }
    if(ch == 'A')
        qsort(input,count,sizeof(int),cmpA);
    else
        qsort(input,count,sizeof(int),cmpB);
    for(int i = 0;i < count;i++)
        printf("%d ",input[i]);

    return 0;
}

