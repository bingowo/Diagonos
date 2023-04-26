#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{
    int len1,len2,i;
    len1 = **(int**)a,len2 = **(int**)b;
    if(len1 < len2)
    {
        for(i = 1;i < len1-1;i++)
        {
            if(*(*(int**)a+i) != *(*(int**)b+i))
                return *(*(int**)b+i) - *(*(int**)a+i);
        }
        return 1;
    }
    else if(len1 > len2)
    {
        for(i = 1;i < len2-1;i++)
        {
            if(*(*(int**)a+i) != *(*(int**)b+i))
                return *(*(int**)b+i) - *(*(int**)a+i);
        }
        return -1;
    }
    else
    {
        for(i = 1;i < len1 - 1;i++)
        {
            if(*(*(int**)a+i) != *(*(int**)b+i))
                return *(*(int**)b+i) - *(*(int**)a+i);
        }
    }
}
int main()
{
    int T,i;
    scanf("%d",&T);
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
            input[j] = (int*)malloc((count+1)*sizeof(int));
            input[j][0] = count;
            for(int k = 1;k < count;k++)
                input[j][k] = tempt[k - 1];
        }
        qsort(input,N,sizeof(int*),cmp);
        for(int j = 0;j < N;j++)
        {
            for(int k = 1;k < input[j][0]+1;k++)
            {
                printf("%d%c",input[j][k],(k == input[j][0])?'\n':' ');
            }
            free(input[j]);
        }
        free(input);

    }
    return 0;
}
