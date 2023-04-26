#include <stdio.h>
#include <stdlib.h>

int acmp(const void* a,const void* b)
{
    int aa=*(int*)a,bb=*(int*)b;
    return aa-bb;
}

int dcmp(const void* a,const void* b)
{
    int aa=*(int*)a,bb=*(int*)b;
    return bb-aa;
}

int main()
{
    int arr[1001],t[101],x=0,j=0;
    char ch;
    scanf("%c",&ch);
    for(int i=0;i<1001;i++)
        arr[i]=-1;
    while(scanf("%d",&x)!=EOF)
    {
        if(arr[x]==-1)
        {
            arr[x]=x;
            t[j]=x;
            j++;
        }
    }
    if(ch=='A') qsort(t,j,sizeof(t[0]),acmp);
    else qsort(t,j,sizeof(t[0]),dcmp);
    for(int i=0;i<j;i++)
        printf("%d ",t[i]);
    return 0;
}
