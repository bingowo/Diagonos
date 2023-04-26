#include <stdlib.h>
#include <stdio.h>

int cmp(const void*s1,const void*s2)
{
    return *(int*)s1 - *(int*)s2;
}

int main()
{
    int m,n,i,j;
    scanf("%d",&m);
    int A[m];
    for(i = 0;i < m;i++)
    {
        scanf("%d",&A[i]);
    }
    scanf("%d",&n);
    int B[n],cnt = 0;
    for(i = 0;i < n;i++)
    {
        scanf("%d",&B[i]);
    }
    for(i = 0;i < m;i++)
    {
        for(j = 0;j < n;j++)
        {
            if(B[j] == A[i])
            {
                printf("%d ",B[j]);
                cnt++;
                B[j] = -1;
            }
        }
    }
    qsort(B,n,sizeof(int),cmp);
    for(i = n - cnt;i < n;i++)
    {
        printf("%d%c",B[i],(i == n - 1)?'\n':' ');
    }
    return 0;

}