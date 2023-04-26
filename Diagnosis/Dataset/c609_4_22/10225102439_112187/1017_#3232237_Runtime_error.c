#include <stdio.h>
#include <stdlib.h>
int cmpA(const void* a,const void* b)
{
    int x=*((int *)a),y=*((int *)b);
    return x-y;
}
int cmpD(const void* a,const void* b)
{
    int x=*((int *)a),y=*((int *)b);
    return y-x;
}

int main()
{
    char ch;
    scanf("%c\n",&ch);
    if (ch=='A')
    {
        int a[1000],b[1000],i=0,j=0,t=0;
        while ((scanf("%d",&a[i++]))!=-1);
        int len=i;
        qsort(a,len,sizeof(int),cmpA);
        while (j<len-1)
        {
            if (a[j]!=a[j+1]) {b[t++]=a[j];}
        }
        for (int p=0;p<t;p++)
            printf("%d ",b[p]);
    }
    if (ch=='D')
    {
        int a[1000],b[1000],i=0,j=0,t=0;
        while ((scanf("%d",&a[i++]))!=-1);
        int len=i;
        qsort(a,len,sizeof(int),cmpD);
        while (j<len-1)
        {
            if (a[j]!=a[j+1]) {b[t++]=a[j];}
        }
        for (int p=0;p<t;p++)
            printf("%d ",b[p]);
    }
    return 0;
}