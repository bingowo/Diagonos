#include <stdio.h>
#include <stdlib.h>

void kk(struct *a)
int count(int a);
int cmp(const void *a,const void *b);

struct mm
{
    int a;
    int b;
};
int main()
{
    int T,i,j;
    scanf("%d",&n);
    for(i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        scanf("%d",N);
        struct mm m[N];
        swap(m[N]);
        for(j=0;j<N-1;j++)
        {
            printf("%d",m[j].a);
            printf(" ");
        }
        printf("%d\n",m[N].a);
    }
    return 0;
}
void kk(struct *a)
{
    for(i=0;i<N;i++)
    {
        m[i].b=count(m[i].a);
    }
    qsort(a,N,sizeof(a[0]),cmp);
}
int cmp(const void *pa,const void *pb)
{
      return *(int*)pa.b-*(int*)pb.b;
 }
int count(int a)
{
    int j=1,num=0;
    for(int i=0;i<63;i++)
    {
        if(a|1==a)num++;
        j*=2
    }
    return num;
}
