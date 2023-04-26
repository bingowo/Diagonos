#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    char s[25];
}list1;
typedef struct{
    int num;
    char s[25];
}list;
int cmp1(const void*a,const void*b)
{
    list1 *x=(list1*)a;
    list1 *y=(list1*)b;
    return strcmp(x->s,y->s);
}
int cmp(const void*a,const void*b)
{
    list *x=(list*)a;
    list *y=(list*)b;
    if(x->num!=y->num)
    {
        return x->num-y->num;
    }
    else
    {
        return strcmp(x->s,y->s);
    }
}
int main()
{
    int id=0,n;
    scanf("%d",&n);
    list1 a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%s",a[i].s);
    }
    qsort(a,n,sizeof(list1),cmp1);
    list b[n];id=0;
    strcpy(b[0].s,a[0].s);
    b[0].num=1;
    for(int i=1;i<n;i++)
    {
        if(strcmp(b[id].s,a[i].s)==0)
        {
            b[id].num++;
        }
        else
        {
            id++;
            strcpy(b[id].s,a[i].s);
            b[id].num=1;
        }
    }
     qsort(b,id+1,sizeof(list),cmp);
    for(int i=0;i<=id;i++)
    {
        printf("%s\n",b[i].s);
    }
    return 0;
}