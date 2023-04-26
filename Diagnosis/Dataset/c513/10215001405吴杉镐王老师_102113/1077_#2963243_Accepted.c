#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int A[1005],B[1005],pos[1005],n,m;

int cmp(const void* a,const void* b)
{
    int x=*(int *)a,y=*(int *)b;
    if(pos[x]!=pos[y]) return pos[y]-pos[x]; //A中未出现的元素权重自然就小
    else return x-y;
}

int main()
{
    for(int i=0;i<=1000;i++)
        pos[i]=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&A[i]);
        pos[A[i]]=n-i+1; //相当于权重
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
        scanf("%d",&B[i]);
    qsort(B+1,m,sizeof(int),cmp);
    for(int i=1;i<=m;i++)
        printf("%d ",B[i]);
    return 0;
}
//主要是建立”权重“的模型

