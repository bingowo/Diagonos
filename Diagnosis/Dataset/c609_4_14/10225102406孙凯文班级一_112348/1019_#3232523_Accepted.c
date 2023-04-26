#include<stdio.h>
#include<stdlib.h>
int cmp(const void*A,const void*B)
{   int q=0,w=0;
    int aa=*(int *)A;
    int bb=*(int *)B;
    int aaa=aa;
    int bbb=bb;
    while(aa!=0)
    {
        q++;
        aa=aa/10;
    }
    while(bb!=0)
    {
        w++;
        bb=bb/10;
    }
    if(q>w) return -1;
    else if(q<w) return 1;
    else if(aaa<bbb) return -1;
    else return 1;
}
int main()
{
    int i=0;
    int a,b[1000000];
    while(scanf("%d",&a)!=EOF)
    {
        b[i]=a;
        i++;
    }
    qsort(b,i,sizeof(b[0]),cmp);
    for(int j=0;j<i;j++)
    {
        printf("%d",b[j]);
        if(j+1!=i) printf(" ");
    }
    return 0;
}
