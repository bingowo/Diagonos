#include<stdio.h>
#include<stdlib.h>

int cmpA(const void* a,const void* b);
int cmpD(const void* a,const void* b);
int main()
{
    char a,c;
    int x[100],i=0;
    scanf("%c\n",&a);
    do
    {    
        scanf("%d",&x[i]);
        i++;
    }while((c=getchar())!='\n'&&c!=EOF);
    if (a=='A')
        qsort(x,i,sizeof(int),cmpA);
    else if (a=='D')
        qsort(x,i,sizeof(int),cmpD);
    int y[100],k=1;
    y[0]=x[0];
    for (int j=1;j<i;j++)
    {
        if (x[j]!=x[j-1])
            y[k++]=x[j];
    }
    for (int j=0;j<k;j++)
    {
        if (j!=i-1)
            printf("%d ",y[j]);
        else 
            printf("%d\n",y[j]);
    }
}
int cmpA(const void* a,const void* b)
{
    return (*(int*)a-*(int*)b);
}

int cmpD(const void* a,const void* b)
{
    return (*(int*)b-*(int*)a);
}