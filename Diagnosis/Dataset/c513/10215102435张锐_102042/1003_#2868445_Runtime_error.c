#include <stdio.h>
#include <stdlib.h>

int ones(unsigned a)
{
   return a==0?0:ones(a/2)+a%2;
}
int cmp(const void*a,const void*b)
{
    int t;
    unsigned ia=*(unsigned*)a,ib=*(unsigned *)b;
    if(t=ones(ib)-ones(ia)) return t;
    if(ia>ib) return 1;
    if(ia<ib) return -1;
    return 0;
}
void Sort(unsigned *p, unsigned n)
{
    qsort(p,n,sizeof(*p),cmp);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        int s[100];
        printf("case #%d:\n",i);
        for(int j=0;j<n;j++)
        {
            scanf("%d",&s[j]);
        }
        Sort(*s,n);
        for(int k=0;k<n;k++)
        {
            printf("%d ",s[k]);
        }
        printf("\n");
    }
    return 0;
}
