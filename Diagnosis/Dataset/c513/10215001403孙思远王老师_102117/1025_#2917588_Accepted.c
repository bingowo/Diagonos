#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ccf
{
    char st[100];
    int num;
};
int cmp(const void *a,const void *b)
{
    struct ccf *p1,*p2;
    p1=(struct ccf *)a;
    p2=(struct ccf *)b;
    if(p1->num!=p2->num)
        return p2->num-p1->num;
    else
        return strcmp(p1->st,p2->st);
}
int main()
{
    int t,T;
    scanf("%d",&T);
    for(t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        int i,n;
        scanf("%d",&n);
        struct ccf cf[n];
        for(i=0;i<n;i++)
        {
            scanf("%s",cf[i].st);
            int j,len;
            cf[i].num=0;
            len=strlen(cf[i].st);
            for(j=0;j<len;j++)
            {
                int j2,flag=1;
                for(j2=0;j2<j;j2++)
                {
                    if(cf[i].st[j]==cf[i].st[j2])
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag)
                    cf[i].num++;
            }
        }
        qsort(cf,n,sizeof(cf[0]),cmp);
            for(i=0;i<n;i++)
                printf("%s\n",cf[i].st);
    }
    return 0;
}
