#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    char s[15];
    int len;
} list;
char a[5005],b[5005];
int cmp(const void *a,const void *b)
{
    list *x=(list*)a;
    list*y= (list*)b;
    return x->len-y->len;
}
int main()
{
    int f=-1,n,i,tep,tep1,max=0;
    scanf("%d\n",&n);
    list *t=(list*)malloc(sizeof(list)*n);
    for(i=0; i<n; i++)
    {
        scanf("%s",t[i].s);
        t[i].len=strlen(t[i].s);
        if(strlen(t[i].s)>max)
            max=strlen(t[i].s);
    }
    qsort(t,n,sizeof(list),cmp);
    scanf("%s",a);
    int len=strlen(a);
    i=0;
    while(a[i])
    {
        f=-1;
        tep=max;
        while(tep>1)
        {
            tep1=n-1;
            strncpy(b,a+i,tep);
            b[tep]='\0';
            while(tep1>=0)
            {
                if(t[tep1].len!=strlen(b))
                    tep1--;
                else
                {

                    if(strcmp(t[tep1].s,b)==0)
                    {
                        printf("%s ",b);
                        f=1;
                        break;
                    }
                    else
                        tep1--;
                }
            }
            if(f==1)
                break;
            tep--;
        }
        if(tep==1)
        {
            printf("%c ",a[i]);
            i++;
        }
        else
        {
            i+=strlen(b);
        }

    }
    free(t);
    return 0;
}
