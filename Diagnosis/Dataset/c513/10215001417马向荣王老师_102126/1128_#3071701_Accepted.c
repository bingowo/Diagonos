#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct lj
{
    char ym[300],xndz[300];
    char q[301];
};
int cmp(const void *a,const void *b)
{
    struct lj *c=(struct lj *)a;
    struct lj *d=(struct lj *)b;
    if(strcmp(c->ym,d->ym)!=0) return strcmp(c->ym,d->ym);
    else return strcmp(c->xndz,d->xndz);
}

int main()
{
    int n,j,e,k=0;
    scanf("%d\n",&n);
    char s[301];
    struct lj p[n];
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        if(s[4]=='s') continue;
        strcpy(p[k].q,s);
        for(j=7;j!='/'&&j<strlen(s);j++)
        {
            p[k].ym[j-7]=s[j];
        }
        p[k].ym[j-7]='\0';
        for(e=j;e<strlen(s);e++)
        {
            p[k].xndz[e-j]=s[e];
        }
        p[k].xndz[e-j]='\0';
        k++;
    }
    qsort(p,k,sizeof(p[0]),cmp);
    for(int i=0;i<k;i++)
    {
        printf("%s\n",p[i].q);
    }
    return 0;
}


