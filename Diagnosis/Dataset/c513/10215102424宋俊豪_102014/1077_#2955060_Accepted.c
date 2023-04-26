#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void *a,const void *b)
{
    int x=*(int*)a;int y=*(int*)b;
    if(x>y)
        return 1;
    else
        return -1;
}
void swap(int b[],int id,int i)
{
    int t;
    t=b[id];b[id]=b[i];b[i]=t;
}
int main()
{
    int id=0,m,n,a[502],b[502];
    memset(a,0,502);
    memset(b,0,502);
    scanf("%d",&m);
    for(int i=0; i<m; i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&b[i]);
    }
    for(int j=0; j<m; j++)
    {
        for(int i=0; i<n; i++)
        {
            if(b[i]==a[j])
            {
                  swap(b,id,i);
                  id++;
            }
        }
    }
    qsort(b+id,n-id,sizeof(int),cmp);
    for(int i=0;i<n;i++)
        printf("%d%c",b[i],i==n-1?'\n':' ');
    return 0;
}
