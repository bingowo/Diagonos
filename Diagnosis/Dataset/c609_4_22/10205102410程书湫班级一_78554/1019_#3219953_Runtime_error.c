#include <stdio.h>
#include <stdlib.h>

struct data
{
    int a;
    int cnt;
};
int cmp(const void *a,const void *b)
{
    struct data d1,d2;
    d1=*((struct data*)a);
    d2=*((struct data*)b);
    if(d1.cnt!=d2.cnt)
    {
        if(d1.cnt>d2.cnt) return -1;
        else return 1;
    }
    else{if(d1.a>d2.a) return 1;
    else return -1;}
}
int main()
{
    char ch;
    struct data p[100001];
    int i=0;
    do
    {
        scanf("%d",&p[i].a);
        int n=(p[i].a>0?p[i].a:-p[i].a);
        if(p[i].a==0) p[i].cnt=1;
        else{
            p[i].cnt=0;
            do
            {
                n=n/10;
                p[i].cnt++;
            }while(n);
        }
        i++;
    }while((ch=getchar())!='\n');
    qsort(p,i,sizeof(p[0]),cmp);
    for(int j=0;j<i;j++) printf("%d%c",p[j].a,(j==i-1?'\n':' '));
    return 0;
}
