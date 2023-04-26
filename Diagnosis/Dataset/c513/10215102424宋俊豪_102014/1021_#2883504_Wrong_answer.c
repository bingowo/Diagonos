#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char l[50];
    int ll[50];
} list;
int slo(list *t,int a[128])
{
    int i=0,j=0;
    char c;
    while((c=getchar())!='\n')
    {

        if (c==' ')
        {
            i++;
            j=0;
        }
        else
        {
            t[i].l[j]=c;
            t[i].ll[j]=a[c];
            j++;
        }

    }
    return i;
}
int cmp(const void* c,const void*b)
{
    int i=0;
    list* ax=(list*)c;
    list* bx=(list*)b;
    while (ax->ll[i]==bx->ll[i])
    {
        i++;
    }
    return (ax->ll[i]-bx->ll[i]);
}
int main()
{
    int len,a[128];
    char s[30];
    while (scanf("%s",s)!=EOF)
    {
        for(int i=0; i<128; i++)
            a[i]=0;
        for (int i=0; i<strlen(s); i++)
        {
            a[s[i]]=i+1;
            a[s[i]+32]=i+1;
        }
        getchar();
        list* t=(list*)malloc(sizeof(list)*100);
        len=slo(t,a);
        qsort(t,len+1,sizeof(t[0]),cmp);
        for (int i=0; i<len+1; i++)
            if (i==len)
                printf("%s\n",t[i].l);
            else
                printf("%s ",t[i].l);
        for (int i=0; i<len+1; i++)
        memset(t[i].l,0,sizeof(t[i]));
        free(t);
        
    }
    return 0;
}

