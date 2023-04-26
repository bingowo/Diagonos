#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void* a,const void* b)
{
    char *c,*d,*e,*f;
    e=(char*)malloc(100*sizeof(char));
    f=(char*)malloc(100*sizeof(char));
    c=*(char**)a;
    d=*(char**)b;
    int j=0,flag1=0,flag2=0,g,h;
    for(int i=0;i<strlen(c);i++)
    {
        if(isdigit(c[i]))
        {
            e[j]=c[i];
            j++;
            flag1=1;
        }
    }
    if(flag1==1)
        g=atoi(e);

    j=0;
    for(int i=0;i<strlen(d);i++)
    {
        if(isdigit(d[i]))
        {
            f[j]=d[i];
            j++;
            flag2=1;
        }
    }
    if(flag2==1)
        h=atoi(f);
    free(e);
    free(f);
    if(flag1==1 &&flag2==0) return 1;
    else if(flag1==0 && flag2==1) return -1;
    else if(flag1==0 && flag2==0) return strcmp(c,d);
    else
    {
        if(g>h) return 1;
        else if(g<h) return -1;
        else return strcmp(c,d);
    }

}
int main()
{
    int i,n=0;
    char **a,*s;
    s=(char*)malloc(31*sizeof(char));
    a=(char**)malloc(100*sizeof(char*));
    while(scanf("%s",s)!=EOF)
    {
        a[n]=(char*)malloc((strlen(s)+1)*sizeof(char));
        strcpy(a[n],s);
        n++;
    }
    qsort(a,n,sizeof(a[0]),cmp);
    for(i=0;i<n;i++)
    {
        printf("%s ",a[i]);

    }
    free(a[i]);
    free(a);
    return 0;
}
