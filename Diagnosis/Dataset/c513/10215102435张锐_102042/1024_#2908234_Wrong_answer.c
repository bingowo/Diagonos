#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char name[50];
    int yes[15];
    int sum;
}G;
int cmp(const void *a,const void *b)
{
    G *s1=(G *) a,*s2=(G *) b;
    if(s1->sum<s2->sum) return 1;
    else return -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int people,ti,min;
        scanf("%d%d%d",&people,&ti,&min);
        G *p=(G *) malloc(people*sizeof(G));
        int *A=(int *) malloc(ti*sizeof(int));
        int j=0;A[0]=0;int i1=1;
        for(;i1<=ti;i1++) {scanf("%d",&A[i1]);}
        for(j=0;j<people;j++)
        {
            scanf("%s",&p[j].name);
            int k=0;
            scanf("%d",&k);
            for(int n=0;n<k;n++)
            {
                scanf("%d",&p[j].yes[n]);
            }
            p[j].sum=0;
            for(int n=0;n<k;n++)
            {
                p[j].sum+=A[p->yes[n]];
            }
        }
        qsort(p,people,sizeof(p[0]),cmp);
        int s=0;
        for(int k=0;k<people;k++)
        {
            if(p[k].sum>=min) s++;
            else break;
        }
        printf("case #%d:\n",i);
        printf("%d\n",s);
        for(j=0;j<s;j++) {printf("%s ",p[j].name);printf("%d\n",p[j].sum);}
        free(p);
        free(A);
    }
    return 0;
}
