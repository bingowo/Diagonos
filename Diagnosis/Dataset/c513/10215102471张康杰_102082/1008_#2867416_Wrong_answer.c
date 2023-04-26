#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int input1,input2,same = 0,j;
        scanf("%d %d",&input1, &input2);
        for(j = 0;j < 32;j++)
        {
            if(input1&(1<<j) == input2&(1<<j))
                same++;

        }
        printf("%d\n",same);
    }

    return 0;
}
