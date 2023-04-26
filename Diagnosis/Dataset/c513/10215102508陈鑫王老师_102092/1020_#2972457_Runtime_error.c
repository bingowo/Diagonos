#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct FILE{
    char year[11];
    char time[6];
    char vol[9];
    char name[64];

};
int cmp1(const void*a,const void* b)
{
    struct FILE* x=(struct FILE*)a;
    struct FILE* y=(struct FILE*)b;
    return strcmp(x->name,y->name);
}
int cmp2(const void*a,const void*b)
{
    struct FILE* x=(struct FILE*)a;
    struct FILE* y=(struct FILE*)b;
    if(strlen(x->vol)!=(strlen(y->vol))) return strlen(x->vol)-strlen(y->vol);
    else
    {
        for(int i=0;i<strlen(x->vol);i++)
        {
            if(x->vol[i]!=y->vol[i])
            {
                return x->vol[i]<y->vol[i]?-1:1;
                break;
            }
        }
        return strcmp(x->name,y->name);

    }
}
int cmp3(const void*a,const void*b)
{
    struct FILE* x=(struct FILE*)a;
    struct FILE* y=(struct FILE*)b;
    for(int i=0;i<strlen(x->year);i++)
    {
        if(x->year[i]!=x->year[i])
        {
            return x->year[i]<y->year[i]?-1:1;
            break;
        }
    }
    for(int i=0;i<strlen(x->time);i++)
    {
        if(x->time[i]!=y->time[i])
        {
            return x->time[i]<y->time[i]?-1:1;
            break;
        }
    }
    return strcmp(x->name,y->name);
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n)
    {

        {
            struct FILE ans[n];
            memset(ans,'0',sizeof(ans));
            for(int i=0;i<n;i++)
            {
                char s1[11],s2[6];
                char s3[9];
                char s4[64];
                scanf("%s %s %s %s",s1,s2,s3,s4);
                ans[i].year[11]=s1;
                ans[i].time[6]=s2;
                ans[i].vol[9]=s3;
                ans[i].name[64]=s4;

            }
            char c,s[11];
            c=getchar();
            gets(s);
            if(s=="LIST /NAME")
                qsort(ans,n,sizeof(ans[0]),cmp1);
            else if(s=="LIST /SIZE")
                qsort(ans,n,sizeof(ans[0]),cmp2);
            else
                qsort(ans,n,sizeof(ans[0]),cmp3);
            for(int i=0;i<n;i++)
            {
                printf("%s%c%s%16s%c%s\n",ans[i].year,' ',ans[i].time,ans[i].vol,' ',ans[i].name);
            }
            scanf("%d",&n);
            if(n)
            printf("\n");



        }

    }
}
