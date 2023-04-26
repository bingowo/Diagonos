#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{
    int len1,len2,i;
    len1 = sizeof(*(int**)a)/sizeof(int),len2 = sizeof(*(int**)b)/sizeof(int);
    if(len1 < len2)
    {
        for(i = 0;i < len1-1;i++)
        {
            if(*(*(char**)a+i) != *(*(char**)b+i))
                return *(*(char**)b+i) - *(*(char**)a+i);
        }
        return 1;
    }
    else if(len1 > len2)
    {
        for(i = 0;i < len2-1;i++)
        {
            if(*(*(char**)a+i) != *(*(char**)b+i))
                return *(*(char**)b+i) - *(*(char**)a+i);
        }
        return -1;
    }
    else
    {
        for(i = 0;i < len1 - 1;i++)
        {
            if(*(*(char**)a+i) != *(*(char**)b+i))
                return *(*(char**)b+i) - *(*(char**)a+i);
        }
    }
}
int main()
{
    int T,i;
    for(i = 0;i < T;i++)
    {
        int**input;
        int N;
        scanf("%d",&N);
        input = (int**)malloc(N*sizeof(int*));
        for(int j = 0;j < N;j++)
        {
            int tempt[50];
            int count = 0;
            while(scanf("%d",&tempt[count]))
            {
                if(tempt[count] == -1)
                    break;
                count++;
            }
            count--;
            input[j] = (int*)malloc((count)*sizeof(int));
            for(int k = 0;k < count;k++)
                input[j][k] = tempt[k];
        }
        qsort(input,N,sizeof(int*),cmp);
        for(int j = 0;j < N;j++)
        {
            for(int k = 0;k < sizeof(input[j])/sizeof(int)-1;k++)
            {
                printf("%d%c",input[j][k],(k == sizeof(input[j])/sizeof(int)-2)?'\n':' ');
            }
            free(input[j]);
        }
        free(input);

    }
    return 0;
}