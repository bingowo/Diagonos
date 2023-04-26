#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    int a[51];
} list;
int cmp1(const void *c,const void *b)
{
    list* x=(list*)c;
    list* y=(list*)b;
    int i=0;
    while (x->a[i]==y->a[i])
        i++;
    return y->a[i]-x->a[i];
}
int main()
{
    int n,n1,j,cnt;
    scanf("%d",&n);
    for (int i=0; i<n; i++)
    {
        scanf("%d",&n1);
        list *t=(list*)malloc(n1*sizeof(list));
        for(int q=0; q<n1; q++)
        {
            j=0;
            scanf("%d",&t[q].a[j]);
            while (t[q].a[j]!=-1)
            {
                j++;
                scanf("%d",&t[q].a[j]);
            }
        }
        qsort(t,n1,sizeof(list),cmp1);
        for(int j=0;j<n1;j++)
        {cnt=0;
         do{printf("%d ",t[j].a[cnt]);
         cnt++;

         }while(t[j].a[cnt]!=-1);
        printf("\n");
        }
        free(t);
    }
    return 0;
}
