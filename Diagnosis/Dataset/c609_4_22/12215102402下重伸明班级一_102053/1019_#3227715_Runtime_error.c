#include<stdio.h>
#include<stdlib.h>
int tongji(int x)
{
    int i=0;
    if(x<0)
        x=x*-1; //xingcan bugaibian
    for(;x>0;i++)
    {
        x=x/10;
    }
    return i; 
}
int comp(const void*p1,const void*p2)
{
    int x;
    int n1,n2;
    n1=*(int*)p1;
    n2=*(int*)p2;
    x=tongji(n1)-tongji(n2);
    if(x!=0)
    {
        return -x;
    }
    else
    {
        if((n1-n2)<0)
            x=-1;
        else
            x=1;
        return x;
    }
}
int main()
{
    int a[100000],n,m;
    int i=0;
    for(;scanf("%d",&n)==1;i++)
    {
        a[i]=n;
    }
    int b[i];
    
    qsort(a,i,sizeof(a[0]),comp);
    
    for(int z=0;z<i;z++)
    {
        printf("%d ",a[z]);
    }
    
 
}