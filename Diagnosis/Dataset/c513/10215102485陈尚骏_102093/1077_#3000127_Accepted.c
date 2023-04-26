#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int num;
    int flag;
}B;

int cmp(const void*a,const void*b)
{
    B a1,b1;
    a1=*(B*)a;b1=*(B*)b;
    if(a1.flag==-1&&b1.flag==-1)
    {
        if(a1.num<b1.num) return -1;
        else return 1;
    }
    else if(a1.flag==-1&&b1.flag!=-1) return 1;
    else if(a1.flag!=-1&&b1.flag==-1) return -1;
    else return a1.flag-b1.flag;
}

int main()
{
    int m,n;
    int a[501];
    B b[501];
    int i;
    scanf("%d",&m);
    for(i=0;i<m;i++)
        scanf("%d",&a[i]);
    for(i=0;i<501;i++)
        b[i].flag=-1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i].num);
        for(int j=0;j<m;j++)
        {
            if(a[j]==b[i].num){b[i].flag=j;break;}
        }
    }
    qsort(b,n,sizeof(B),cmp);
    for(i=0;i<n;i++)
        printf("%d ",b[i].num);
    printf("\n");
    return 0;
}
