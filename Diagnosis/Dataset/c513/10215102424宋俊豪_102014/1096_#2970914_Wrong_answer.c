#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct{int a;int b;}l;
int cmp(const void *a,const void *b)
{
    l *x=(l *)a;
    l *y=(l*)b;
    return x->a-y->a;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int num,f=1;
        scanf("%d",&num);
        int c[128]= {0},d[128]= {0};
        l* t=(l*)malloc(sizeof(l)*num);
        for(int j=0; j<num; j++)
        {
            scanf("%d%d",&t[j].a,&t[j].b);
            c[t[j].a]++;
            d[t[j].b]++;
        }
        qsort(t,num,sizeof(l),cmp);
        for(int j=0; j<num-1; j++)
        {
            if (t[j].a==t[j+1].a)
            {
                f=-1;
                break;
            }
        }
        for(int j=0; j<num; j++)
        {
            if(c[t[j].b]==0||c[t[j].b]==d[t[j].a])
                ;
            else
            {
                f=-1;
                break;
            }
        }
        if(f==-1)
            printf("Poor dxw!\n");
        else
            printf("Lucky dxw!\n");
        free(t);
    }
    return 0;
}
