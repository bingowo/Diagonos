#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp1(const void* a,const void* b)
{
    char c=*(char*)a,d=*(char*)b;
    return c-d;
}
int num(char *x)
{
    int n,sum,i;
    sum=1;
    char a[21],m;
    strcpy(a,x);
    n=strlen(a);
    qsort(a,n,sizeof(a[0]),cmp1);
    m=a[0];
    for(i=1;i<strlen(a);i++)
    {
        if(a[i]!=m)
        {
            sum++;
            m=a[i];
        }
    }
    return sum;
}
int cmp(const void* a,const void* b)
{
    char *c=*(char**)a,*d=*(char**)b;
    int num1=num(c),num2=num(d);
    if(num1!=num2) return num2-num1;
    return strcmp(c,d);
}
int main()
{
    int T,i,j,n;
    char **a;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&n);
        a=(char**)malloc(sizeof(char*)*n);
        for(j=0;j<n;j++)
        {
            a[j]=(char*)malloc(sizeof(char)*21);
            scanf("%s",a[j]);
        }
        qsort(a,n,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<n;j++)
        {
            printf("%s\n",a[j]);
        }
    }
    return 0;
}
