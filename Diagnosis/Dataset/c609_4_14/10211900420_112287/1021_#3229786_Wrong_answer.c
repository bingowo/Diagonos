#include<stdio.h>
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
        numa = tab[toupper(c->a[i])-'A'];
        numb = tab[toupper(d->a[j])-'A'];
        if(numa>numb) return 1;
        else if(numa<numb) return -1;
        i++;
        j++;
    }
    return strcmp(c->a,d->a);
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
        for(int j=0;j<26;j++)
        x=0;
        int i=0;
        while(x!='\n')
        {
            scanf("%s",c[i].a);
            scanf("%c",&x);
            i++;
        }
        qsort(c,i,sizeof(c[0]),cmp);
        for(int j=0;j<i;j++)
            printf("%s ",c[j].a);
        printf("\n");
    }
    return 0;
}
