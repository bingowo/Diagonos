#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    int n;
    int s;
    int w;
    int l;
} dui;
int cmp(const void* a,const void*b)
{
    dui *ax=(dui*)a;
    dui *bx=(dui*)b;
    if (ax->s<bx->s)
        return 1;
    else if(ax->s>bx->s)
        return -1;
    else
    {
        if (ax->w<bx->w)
            return 1;
        else if(ax->w>bx->w)
            return -1;
        else
        {
            if (ax->l>bx->l)
                return 1;
            else if (ax->l<bx->l)
                return -1;
            else
            {
                if (ax->n>bx->n)
                    return 1;
                else
                    return -1;
            }
        }
    }
}
int main()
{
    int l,g;
    int a,b,c;
    while(scanf("%d%d",&l,&g)!=EOF)
    {
        if (l==0)
            break;
        else
        {
            dui* t=(dui*)malloc(sizeof(dui)*l);
            for (int i=0; i<l; i++)
            {
                t[i].n=i+1;
                t[i].s=0;
                t[i].w=0;
                t[i].l=0;
            }
            for(int i=0; i<g; i++)
            {
                scanf("%d%d%d",&a,&b,&c);
                if (c==-1)
                {
                    t[b-1].w++;
                    t[b-1].s+=3;
                    t[a-1].s-=1;
                    t[a-1].l++;
                }
                else if(c==1)
                {
                    t[a-1].w++;
                    t[a-1].s+=3;
                    t[b-1].s-=1;
                    t[b-1].l++;
                }
                else
                {
                    t[a-1].s++;
                    t[b-1].s++;
                }
            }
            qsort(t,l,sizeof(t[0]),cmp);
            for (int i=0; i<l; i++)
            {
                if (i==l-1)
                    printf("%d\n",t[i].n);
                else
                    printf("%d ",t[i].n);
            }
            free(t);
        }
    }
    return 0;
}
