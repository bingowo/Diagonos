#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char s[21];
    int num;
}DNA;
int cmp(const void *p1,const void *p2)
{
    DNA *a=p1;
    DNA *b=p2;
    if(a->num > b->num) return 1;
    else if(a->num < b->num) return -1;
    else return strcmp(a->s,b->s);
}
int main()
{
    int n;
    scanf("%d",&n);
    DNA a[n];
    int w=1;
    scanf("%s",a[0].s);
    a[0].num=1;
    for(int i=1;i<n;i++)
    {
        char q[21]={0};
        scanf("%s",q);
        int flag=1;
        for(int j=0;j<w;j++)
        {
            if(!strcmp(a[j].s,q))
            {
                 a[j].num++;
                 flag=0;
                 break;
            }
        }
        if(flag==1)
        {
            a[w].num=1;
            strcpy(a[w++].s,q);
        }
    }
    qsort(a,w,sizeof(a[0]),cmp);
    for(int k=0;k<w;k++) printf("%s\n",a[k].s);
}
