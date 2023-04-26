#include <stdio.h>
#include <stdlib.h>
int A[501]={0};
int B[501]={0};
int m,n;
int posx=502;
int posy=502;
int isinA(int num)
{
    for(int i=0;i<m;i++)
    {
        if(num==A[i])
        {
            return i;
        }
    }

    return 502;
}

int cmp(const void *a,const void*b)
{
    int x=*(int *)a;
    int y=*(int *)b;
    posx=isinA(x);
    posy=isinA(y);
    if((posx!=502)||(posy!=502))
        return posx-posy;
    else return x-y;
}

int main()
{
    scanf("%d",&m);
    for(int i=0;i<m;i++)
        scanf("%d",&A[i]);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&B[i]);
    qsort(B,n,sizeof(int),cmp);
    for(int i=0;i<n;i++)
        printf("%d ",B[i]);
    return 0;
}
