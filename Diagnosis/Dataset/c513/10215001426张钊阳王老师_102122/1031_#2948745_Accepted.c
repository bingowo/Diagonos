#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cmp2(const void * a,const void * b);
    int cmp1(const void * a,const void * b);
    int m;
    scanf("%d",&m);
    for(int z=0;z<m;z++)
    {
        int n;
        int i;
        int count=0;
        int sum=0;
        scanf("%d",&n);

        int *a=(int *)malloc(sizeof(int)*n);
        int *b=(int *)malloc(sizeof(int)*n);
        for(i=0;i<n;i++) scanf("%d",a+i);
        for(i=0;i<n;i++) scanf("%d",b+i);


        //以上是输入环节

        int min=0;
        int p;

        qsort(a,n,sizeof(a[0]),cmp1);
        qsort(b,n,sizeof(b[0]),cmp2);

        for(i=0;i<n;i++)
        {
            min+=a[i]*b[i];
        }

        printf("case #%d:\n",z);
        printf("%d",min);
        printf("\n");
    }
    return 0;
}



int cmp1(const void * a,const void * b)
{
    int *c=(int *)a;
    int *d=(int *)b;
    if(*c!=*d) return *c-*d;
    else return *d-*c;
}
int cmp2(const void * a,const void * b)
{
    int *c=(int *)a;
    int *d=(int *)b;
    if(*c!=*d) return *d-*c;
    else return *c-*d;
}
