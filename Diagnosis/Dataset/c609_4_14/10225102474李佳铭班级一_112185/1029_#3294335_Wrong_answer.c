#include <stdio.h>
#include <stdlib.h>

int ruler[1000];

int count(int a)
{
    if(ruler[a] == -1)
    {
        return -1;
    }
    else
    {
        return ruler[a];
    }
}

int cmp(const void* a,const void* b)
{
    int A = *(int*)a;
    int B = *(int*)b;

    if(count(A) != count(B))
    {
        return count(A) < count(B);
    }
    else
    {
        if(count(A) >= 0)
            return 1;
        else
        {
            return A > B;
        }
    }
}

int main()
{
    int A[500];
    int B[500];
    int AT;
    int BT;
    scanf("%d",&AT);
    for(int i  = 0;i < AT;i++)
        scanf("%d",&A[i]);

    scanf("%d",&BT);
    for(int i  = 0;i < BT;i++)
        scanf("%d",&B[i]);

    for(int i = 0; i < 1000;i++)
    {
        ruler[i] = -1;
    }

    for(int i = 0; i < AT; i++)
    {
        ruler[A[i]] = i;
    }
    qsort(B,BT,sizeof(B[0]),cmp);

    for(int i = 0; i < BT; i++)
    {
        printf("%d ",B[i]);
    }


    return 0;
}
