#include <stdio.h>
#include <stdlib.h>

int A[500]={0},m=0;
int cmp(const void*pa,const void*pb)
{
    int a=*(int*)pa,b=*(int*)pb;
    int signa=-1,signb=-1;
    for(int i=0;i<m;i++)
    {
        if(a==A[i]) signa=i;
        if(b==A[i]) signb=i;
    }
    if(signa!=-1&&signb!=-1) return signa-signb;
    else if(signa!=-1||signb!=-1) return signb-signa;
    else return a-b;
}

int main()
{
    scanf("%d",&m);
    for(int i=0;i<m;i++)
        scanf("%d",&A[i]);

    int n=0;
    scanf("%d",&n);
    int B[500]={0};
    for(int i=0;i<n;i++)
        scanf("%d",&B[i]);

    qsort(B,n,sizeof(B[0]),cmp);
    for(int i=0;i<n;i++)
        printf("%d%c",B[i],i!=n-1?' ':'\n');
    return 0;
}