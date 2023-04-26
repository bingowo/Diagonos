#include<stdio.h>
#include<stdlib.h>

int cmp(const void*c, const void*d);
int cmp1(const void*c, const void*d)
{return *(int*)d-*(int*)c;}

int main()
{
    int m;
    scanf("%d",&m);
    int *a;
    int *p;
    int i;
    a = (int*)malloc(m*sizeof(int));
    p = (int*)malloc(m*sizeof(int));
    for(i=0;i<m;i++){
        scanf("%d",&a[i]);
        p[a[i]]=i;
    }

    int n;
    scanf("%d",&n);
    int *b;
    b=(int*)malloc(n*sizeof(int));
    int j;
    for(j=0;j<n;j++)
    scanf("%d",&b[j]);

    int *outside;
    int *inside;
    outside=(int*)malloc(n*sizeof(int));
    inside=(int*)malloc(n*sizeof(int));

    int k=0,x=0;
    int flag[500]={0};

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

    int cmp(const void*c,const void*d)
    {
        int n1=*(int*)c;
        int n2=*(int*)d;
        return p[n1]-p[n2];
    }

    qsort(inside,x,sizeof(int),cmp);
    qsort(outside,k,sizeof(int),cmp1);

    free(b);
    free(p);
    free(a);

    for(int y=0;y<x;y++)
        printf("%d ",inside[y]);
    for(int z=k-1;z>=0;z--)
        printf("%d ",outside[z]);//问题出在outside后面全是0，所以应该降序排列

    return 0;
}
