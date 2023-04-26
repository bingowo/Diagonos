#include <stdio.h>
#include <stdlib.h>

struct data
{
    int num[100];
    int wei;
};

int cmp(const void* a,const void* b)
{
    struct data d1,d2;
    d1=*((struct data*)a),d2=*((struct data*)b);
    int i,flag=0;
    for(i=0;i<d1.wei&&i<d2.wei;i++)
        {
            if(d1.num[i]<d2.num[i]) {flag=1;break;}
            else if(d1.num[i]>d2.num[i]) {flag=-1;break;}
        }
    if(flag==0) flag=d1.wei-d2.wei;
    return flag;
}

int main()
{
    int N,i;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        int n,j,q;
        scanf("%d",&n);
        struct data NUM[2000];
        for(j=0;j<=2000;j++) for(q=0;q<=100;q++) NUM[j].num[q]=0;
        for(j=0;j<n;j++)
            for(q=0;;q++)
            {
                scanf("%d",&NUM[j].num[q]);
                if(NUM[j].num[q]==-1) {NUM[j].wei=q;break;}
            }
        qsort(NUM,n,sizeof(NUM[0]),cmp);
        for(j=0;j<n;j++)
            for(q=0;q<NUM[j].wei-1;q++) printf("%d ",NUM[j].num[q]);
        printf("%d\n",NUM[j].num[q]);
    }
    return 0;
}

