#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int o;
    int value;
} NUM;

int cmp(const void* a,const void* b)
{
    NUM* pa=(NUM*)a; NUM* pb=(NUM*)b;
    return (pa->value<pb->value)?-1:1;
}

int cmp1(const void* a,const void* b)
{
    int* pa=(int*)a; int* pb=(int*)b;
    return (*pa<*pb)?-1:1;
}

int cmp2(const void* a,const void* b)
{
    NUM* pa=(NUM*)a; NUM* pb=(NUM*)b;
    return (pa->o<pb->o)?-1:1;
}

int main()
{
    int m,n,i,j=0,h=0; int cnt=0;
    scanf("%d",&m);
    NUM* a=(NUM*)malloc(m*sizeof(NUM));
    for (i=0;i<m;i++)
    {
        a[i].o=i;
        scanf("%d",&a[i].value);
    }
    qsort(a,m,sizeof(NUM),cmp);
    scanf("%d",&n);
    int* b=(int*)malloc(n*sizeof(int));
    for (i=0;i<n;i++)
        scanf("%d",&b[i]);
    qsort(b,n,sizeof(int),cmp1);
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            if (b[i]==a[j].value)
            {
                cnt++;
            }
            if (b[i]<a[j].value)
                break;
        }
    }
    NUM* c=(NUM*)malloc(cnt*sizeof(NUM));

    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            if (b[i]==a[j].value)
            {
                c[h].o=a[j].o;
                c[h++].value=a[j].value;
            }
            if (b[i]<a[j].value)
                break;
        }
    }
    h=0;
    if (cnt==0)
    {
        for (i=0;i<n-cnt;i++)
            printf("%d%c",b[i],(i==n-cnt-1)?'\n':' ');
    }
    else
    {

        int* d=(int*)malloc((n-cnt)*sizeof(int));
        for (i=0;i<n;i++)
        {
            for (j=0;j<cnt;j++)
            {
                if (b[i]==c[j].value)
                    break;
                if (b[i]<c[j].value)
                {
                    d[h++]=b[i];
                    break;
                }
                if (b[i]>c[j].value)
                {
                    d[h++]=b[i];
                    break;
                }
            }
        }
        qsort(c,cnt,sizeof(NUM),cmp2);
        qsort(d,n-cnt,sizeof(int),cmp1);
        for (i=0;i<cnt;i++)
            printf("%d ",c[i].value);
        for (i=0;i<n-cnt;i++)
            printf("%d%c",d[i],(i==n-cnt-1)?'\n':' ');
        free(d);
    }

    free(a); free(b); free(c);
    return 0;
}
