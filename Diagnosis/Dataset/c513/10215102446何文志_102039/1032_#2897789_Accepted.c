#include <stdio.h>
#include <stdlib.h>
typedef struct Line
{
    int a[50];
    int cnt;
}line;

int cmp(const void *a,const void *b)
{
    line A = *(line*)a,B = *(line*)b;
    int i = 0;
    while(i<50)
    {
        if(A.a[i]!=B.a[i]){return B.a[i]-A.a[i];}
        else {i++;}
    }
}




int main()
{
    int T = 0;
    scanf("%d",&T);
    for(int i = 0;i<T;i++)
    {
        int N = 0;
        scanf("%d",&N);
        line L[N];memset(L,0,N*sizeof(line));
        for(int j = 0;j<N;j++)
        {
            int temp = 0,cnt = 0;
            while(temp!=-1)
            {
                scanf("%d",&temp);
                if(temp == -1){break;}
                L[j].a[cnt] = temp;cnt++;
            }
            L[j].cnt = cnt;
        }
        qsort(L,N,sizeof(L[0]),cmp);
        for(int j = 0;j<N;j++)
        {
            for(int k = 0;k<L[j].cnt    ;k++)
            {
                printf("%d ",L[j].a[k]);
            }
            printf("\n");
        }
    }
    return 0;
}
