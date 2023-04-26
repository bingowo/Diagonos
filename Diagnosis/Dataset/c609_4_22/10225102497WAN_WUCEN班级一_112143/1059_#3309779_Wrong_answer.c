#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int cnt;
    char v[200];
}BigDouble;

int BigDoublecmp(const BigDouble* a,const BigDouble* b);

int main()
{
    int n=0;
    BigDouble array[200];
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        char c;
        scanf("%c",&c);
        while(c!='\n')
        {
            array[i].v[array[i].cnt]=c;
            scanf("%c",&c);
            array[i].cnt++;
        }
        array[i].v[array[i].cnt]='\0';
    }
    qsort(array,n,sizeof(array[0]),BigDoublecmp);
    for( int i=0;i<n;i++)
        printf("%s\n",array[i].v);
}

int BigDoublecmp(const BigDouble* a,const BigDouble* b)
{
    int lena=0,lenb=0,signa=0,signb=0,plusa=0,plusb=0;
    signa=(((BigDouble*)a)->v[lena]=='-')?-1:1;
    plusa=(((BigDouble*)a)->v[lena]=='+'||(BigDouble*)a->v[lena]=='-')?1:0;
    signb=(((BigDouble*)b)->v[lenb]=='-')?-1:1;
    plusb=(((BigDouble*)b)->v[lenb]=='+'||(BigDouble*)b->v[lenb]=='-')?1:0;
    if(signa!=signb) return signa-signb;
    while(((BigDouble*)a)->v[lena]!='\0'&&((BigDouble*)a)->v[lena]!='.')
        lena++;
    while(((BigDouble*)b)->v[lenb]!='\0'&&((BigDouble*)b)->v[lenb]!='.')
        lenb++;
    if(lena!=lenb) return signa*(lena-lenb-plusa-plusb);

    return signa*strcmp(((BigDouble*)a)->v,((BigDouble*)b)->v+plusb);
}
