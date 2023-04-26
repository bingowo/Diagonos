#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char t1[12];
    char t2[6];
    int n;
    char name[65];
} list;
int cmp1(const void* a,const void*b)
{
    int i=0;
    list* ax=(list*)a;
    list* bx=(list*)b;
    do
    {
        if(ax->t1[i]>bx->t1[i])
            return 1;
        else if (ax->t1[i]<bx->t1[i])
            return -1;
        else
            i++;
    }
    while(i<strlen(ax->t1));
    i=0;
    do
    {
        if(ax->t2[i]>bx->t2[i])
            return 1;
        else if (ax->t2[i]<bx->t2[i])
            return -1;
        else
            i++;
    }
    while(i<strlen(ax->t2));
    i=0;
    do
    {
         if(ax->name[i]>bx->name[i])
            return 1;
        else if (ax->name[i]<bx->name[i])
            return -1;
        else
            i++;
    }while(i<strlen(ax->name));

}
int cmp2(const void* a,const void*b)
{
    int i=0;
    list* ax=(list*)a;
    list* bx=(list*)b;
    if (ax->n>bx->n)
        return 1;
    else if (ax->n<bx->n)
        return -1;
    do
    {
         if(ax->name[i]>bx->name[i])
            return 1;
        else if (ax->name[i]<bx->name[i])
            return -1;
        else
            i++;
    }while(i<strlen(ax->name));
}
int cmp3(const void* a,const void*b)
{
    int i=0;
    list* ax=(list*)a;
    list* bx=(list*)b;
    do
    {
         if(ax->name[i]>bx->name[i])
            return 1;
        else if (ax->name[i]<bx->name[i])
            return -1;
        else
            i++;
    }while(i<strlen(ax->name));
}

int main()
{
    int n,cnt=0;;
    char s[6];
    while(scanf("%d",&n)!=EOF)
    {

        if (n==0)
            break;
        else
        {   if (cnt!=0)
             printf("\n");
            cnt++;
            list* t=(list*)malloc(sizeof(list)*n);
            for (int i=0; i<n; i++)
            {
                scanf("%s",t[i].t1);
                scanf("%s",t[i].t2);
                scanf("%d",&t[i].n);
                scanf("%s",t[i].name);
            }
            scanf("%s",s);
            scanf("%s",s);
            if(s[1]=='T')
            {
                qsort(t,n,sizeof(t[0]),cmp1);
                for(int i=0; i<n; i++)
                {
                    printf("%s ",t[i].t1);
                    printf("%s ",t[i].t2);
                    printf("%16d ",t[i].n);
                    printf("%s\n",t[i].name);
                }
            }
            else if (s[1]=='S')
            {
                qsort(t,n,sizeof(t[0]),cmp2);
                for(int i=0; i<n; i++)
                {
                    printf("%s ",t[i].t1);
                    printf("%s ",t[i].t2);
                    printf("%16d ",t[i].n);
                    printf("%s\n",t[i].name);
                }
            }
            else if(s[1]=='N')
            {
                qsort(t,n,sizeof(t[0]),cmp3);
                for(int i=0; i<n; i++)
                {
                    printf("%s ",t[i].t1);
                    printf("%s ",t[i].t2);
                    printf("%16d ",t[i].n);
                    printf("%s\n",t[i].name);
                }
            }
            free(t);
        }
    }
    return 0;
}
