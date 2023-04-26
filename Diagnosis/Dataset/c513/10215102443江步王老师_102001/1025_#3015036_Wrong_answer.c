#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct a
{
    char s[21];
    int flag[128];
    int num;
}str;

int cmp(const void* a, const void* b);

int main()
{
    int t;
    int i,j,k;

    scanf("%d",&t);
    for (i=0;i<t;++i)
    {
        int n;
        scanf("%d\n",&n);

        str* t= (str* )malloc(sizeof(str)*n);

        for (j=0;j<n;++j)
        {
            t[j].num=0;

            for (k=0;k<128;++k)
            {
                t[j].flag[k]=0;
            }
            
        }

        for (j=0;j<n;++j)
        {
            scanf("%s",t[j].s);
        }

        for (j=0;j<n;++j)
        {
            char* p=t[j].s;

            while (*p)
            {
                if (!t[j].flag[*p])
                {
                    t[j].flag[*p]+=1;
                    t[j].num++;
                }
                
                ++p;
            }
        }

        qsort(t,n,sizeof(str),cmp);

        printf("case #%d:\n",i);

        for (j=0;j<n;++j)
        {
            printf("%s\n",t[j].s);
        }

        free(t);
    }

    return 0;
}

int cmp(const void* a, const void* b)
{
    str* pa = (str* )a;
    str* pb = (str* )b;

    if (pb->num < pa->num)
    {
        return 1;
    }
    else if (pb->num == pa->num && strcmp(pb->s,pa->s)==-1)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}