#include<stdio.h>
#include<stdlib.h>

int cmp(const void*a, const void*b);
int cmp1(const void*a, const void*b)
{return *(int*)b-*(int*)a;}

int main()
{
    int m;
    scanf("%d",&m);
    int a[10000];
    int p[10000];
    int i;
    for(i=0;i<m;i++){
        scanf("%d",&a[i]);
        p[a[i]]=i;
    }

    int n;
    scanf("%d",&n);
    int b[10000];
    int j;
    for(j=0;j<n;j++)
    scanf("%d",&b[j]);

    int outside[10000];
    int inside[10000];
    int k=0,x=0;
    int flag[10000]={0};

    for(j=0;j<n;j++)
    {
        for(i=0;i<m;i++){
            if(b[j]==a[i]){
                flag[j]=1;
                break;
            }
        }
        if(flag[j]==0) outside[k++]=b[j];
        else inside[x++]=b[j];
    }

    int cmp(const void*a,const void*b)
    {
        int n1=*(int*)a;
        int n2=*(int*)b;
        return p[n1]-p[n2];
    }

    qsort(inside,x,sizeof(int),cmp);
    qsort(outside,k,sizeof(int),cmp1);

    for(int y=0;y<x;y++)
        printf("%d ",inside[y]);
    for(int z=k-1;z>=0;z--)
        printf("%d ",outside[z]);//问题出在outside后面全是0，所以应该降序排列
    return 0;
}