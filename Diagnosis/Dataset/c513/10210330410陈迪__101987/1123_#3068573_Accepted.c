#include <stdlib.h>

struct DNA { int cnt; char dna[21]; };

int cmp1(const void*a, const void*b);
int cmp2(const void*a, const void*b);

int main()
{
        int n;
        scanf("%d",&n);
        struct DNA *p =  (struct DNA*)malloc(n*sizeof(struct DNA));
        int i,k;
        for(i=0;i<n;i++) { scanf("%s", (p+i)->dna); (p+i)->cnt=0; }
        qsort(p,n,sizeof(struct DNA),cmp1);
        k=0;
        while(k<n)
        {
            (p+k)->cnt=1;
            for(i=k;i<n;i++) if(strcmp((p+k)->dna,(p+i)->dna)==0) (p+k)->cnt++; else break;
            k=i;
        }
        qsort(p,n,sizeof(struct DNA),cmp2);
        for(i=0;i<n;i++) if((p+i)->cnt) printf("%s\n",(p+i)->dna);
        return 0;
}

int cmp1(const void *a, const void *b)
{
    struct DNA *p, *q;
    p=(struct DNA*)a; q=(struct DNA*)b;
    return strcmp(p->dna,q->dna);
}

int cmp2(const void *a, const void *b)
{
    struct DNA *p, *q;
    p=(struct DNA*)a; q=(struct DNA*)b;
    if(p->cnt==q->cnt) return strcmp(p->dna,q->dna);
    else return p->cnt - q->cnt;
}
