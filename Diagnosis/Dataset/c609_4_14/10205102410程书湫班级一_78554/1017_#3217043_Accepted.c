#include <stdio.h>
#include <stdlib.h>

int cmp1(const void *a,const void *b)
{
    int c,d;
    c=*((int *)a);
    d=*((int *)b);
    return c-d;
}
int cmp2(const void *a,const void *b)
{
    int c,d;
    c=*((int *)a);
    d=*((int *)b);
    return d-c;
}
int main()
{
    char c,ch;
    int k=0,a[1000],s[1000];
    for(int i=0;i<1000;i++)
    {
        a[i]=-1;
    }
    scanf("%c",&c);
    do
    {
        int n;
        scanf("%d",&n);
        if(a[n]==-1)
        {
            a[n]=n;
            s[k++]=n;
        }
    }while((ch=getchar())!='\n');
    if(c=='A')
    {qsort(s,k,sizeof(s[0]),cmp1);}
    else if(c=='D')
    {
        qsort(s,k,sizeof(s[0]),cmp2);
    }
    for(int i=0;i<k;i++)
        printf("%d%c",s[i],(i==k-1?'\n':' '));
    return 0;
}
