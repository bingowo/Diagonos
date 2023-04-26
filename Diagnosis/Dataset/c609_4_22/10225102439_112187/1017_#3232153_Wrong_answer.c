#include <stdio.h>
#include <stdlib.h>
int cmpA(const void *a,const void *b)
{
    int x=*((int*)a),y=*((int*)b);
    return x-y;
}

int cmpD(const void *a,const void *b)
{
    int x=*((int*)a),y=*((int*)b);
    return y-x;
}

int main()
{
    char ch;
    scanf("%c\n",&ch);
    if (ch=='A')
    {
        int a[1000],i=0,t=0,j=0;
        while ((scanf("%d",a+i))!=-1) i++;
        qsort(a,i,sizeof(int),cmpA);
        for (;j<i-1;j++)
            if (a[j]==a[j+1]) a[j]=0;
        while (t<j)
        {
            if (a[t++]==0) continue;
            printf("%d ",a[t++]);
        }
        printf("%d",a[t]);
    }
    else
    {
        int a[1000],i=0,j=0,t=0,b[1000];
        while ((scanf("%d",a+i))!=-1) i++;
        qsort(a,i,sizeof(int),cmpD);
        for (int p=0;j<i-1;j++)
            if (a[j]==a[j+1]) b[p++]=a[j];
        while (t<i)
        {
            printf("%d ",b[t++]);
        }
    }
    return 0;
}
