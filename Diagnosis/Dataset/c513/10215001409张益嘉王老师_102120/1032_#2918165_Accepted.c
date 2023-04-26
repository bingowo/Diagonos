#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int lie[100]
}data;

int cmp(const void*a,const void*b)
{
    int m;
    data aa=*((data*)a);
    data bb=*((data*)b);
    for(m=0;m<60;m++)
    {
        if(aa.lie[m]>bb.lie[m]) return -1;
        else if(aa.lie[m]<bb.lie[m]) return 1;
        else continue;
    }
    if(m>=60) return 1;

}

int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int n,j,k;
        data a[1200];
        memset(a,0,sizeof(data)*1200);
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            for(k=0;;k++)
            {
                scanf("%d",&a[j].lie[k]);
                if(a[j].lie[k]==-1) break;
            }
        }
        qsort(a,n,sizeof(data),cmp);
        for(j=0;j<n;j++)
        {
            for(k=0;;k++)
            {
                if(a[j].lie[k]==-1) {printf("\n");break;}
                else printf("%d ",a[j].lie[k]);
            }
        }

    }
}
