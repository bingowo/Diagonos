#include <stdio.h>
#include <stdlib.h>

int Tto2333(int x)
{
    if(x>0)
    {
        Tto2333(x/2333);
        printf("%d ",x%2333);
    }
    else return 0;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        if(N==0){printf("0");continue;}
        if(N<0)
        {
            printf("-");
            N=-N;
        }
        Tto2333(N);
        printf("\n");
    }
    return 0;
}
