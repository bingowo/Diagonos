#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int p;
    int w;
    int l;
    int num;
}score;
int cmp(const void *a,const void *b)
{
    score *pa=(score*)a,*pb=(score*)b;
    if(pa->p > pb->p) return -1;
    else if (pa->p < pb->p) return 1;
    else if(pa->w > pb->w) return -1;
    else if(pa->w < pb->w) return 1;
    else if(pa->l < pb->l) return -1;
    else if(pa->l > pb->l) return 1;
    else if(pa->num > pb->num) return 1;
    else return -1;
}
int main()
{
    int n,m,i,j,k,a,b,c;
    score s[20];
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(m==0 && n==0)  break;
        for(i=1;i<=10;i++)
        {
            s[i].p=s[i].w=s[i].l=0;
            s[i].num=i;
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            switch (c)
            {
                case 1:s[a].p+=3;s[b].p-=1;s[a].w++;s[b].l++;break;
                case -1:s[a].p-=1;s[b].p+=3;s[a].l++;s[b].w++;break;
                case 0:s[a].p+=1;s[b].p+=1;break;
            }
        }
        qsort(s+1,n,sizeof(score),cmp);
        printf("%d",s[1].num);
        for(i=2;i<=n;i++)  printf(" %d",s[i].num);
        printf("\n");
    }
    return 0;
}