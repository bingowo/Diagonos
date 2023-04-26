#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int T,n,A[100005],id[10005];

int cmp(const void* a,const void* b)
{
    int x=*(int*)a,y=*(int*)b;
    for(int i=0;;i++)
    {
        if(A[x+i] != A[y+i])
            return A[y+i]-A[x+i];
        else if(A[x+i]==-1)
            return 1;
    }
}
int main()
{
    scanf("%d",&T);
    for(int c=0;c<T;c++)
    {
        scanf("%d",&n);
        int l=0;
        for(int i=1;i<=n;i++)
        {
            id[i]=l+1;
            for(int j=1;;j++)
            {
                scanf("%d",&A[j+l]);
                if(A[j+l]==-1)
                {
                    l=j+l;
                    break;
                }
            }
        }
        qsort(id+1,n,sizeof(int),cmp);
        for(int i=1;i<=n;i++)
        {
            for(int j=0;;j++)
            {
                if(A[id[i]+j]==-1)
                    break;
                printf("%d ",A[id[i]+j]);
            }
            puts("");
        }
    }
    return 0;
}

