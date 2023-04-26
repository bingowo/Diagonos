#include<stdio.h>
#include <ctype.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
    char a[21];
}alp;
int tab[27];

int cmp(const void* e,const void* f)
{
    alp *c,*d;
    c=e;
    d=f;
    int i=0,j=0,numa,numb,lena,lenb;
    lena=strlen(c->a);
    lenb=strlen(d->a);
    while(i<=lena || j<=lenb)
    {
        /*if('A'<=c->a[i])
            numa=tab[c->a[i]-'A'];
        else
            numa=tab[c->a[i]-'a'];
        if('A'<=d->a[j])
            numb=tab[d->a[j]-'A'];
        else
            numb=tab[d->a[j]-'a'];
        */
        numa = tab[toupper(c->a[i])-'A'];
        numb = tab[toupper(d->a[j])-'A'];
        if (numa != numb) return numa-numb; // TODO: fixed
        //if(numa>numb) return -1;
        //else if(numa<numb) return 1;
        i++;
        j++;
    }
    return strcmp(c->a, d->a); // use strcmp to replace
}
int main()
{
    char b[21],a[27],x;
    alp c[100];
    while(scanf("%s",a)!=EOF)
    {
        for(int j=0;j<strlen(a);j++)
        {
            int ind=a[j]-'A';
            tab[ind]=j;
        }
        x=0;
        int i=0;
        while(x!='\n')
        {
            scanf("%s",c[i].a);
            //printf("%s",c[i].a);
            scanf("%c",&x);
            //printf("%c",x);
            i++;
        }
        qsort(c,i,sizeof(c[0]),cmp);
        for(int j=0;j<i;j++)
            printf("%s ",c[j].a);
    }
    return 0;
}