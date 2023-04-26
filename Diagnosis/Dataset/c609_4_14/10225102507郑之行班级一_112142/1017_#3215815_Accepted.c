#include <stdio.h>
#include <stdlib.h>

int cmpA(const void* a,const void* b)
{
    if (*(int*)a > *(int*)b)return 1;
    else return -1;
}

int cmpD(const void* a,const void* b)
{
    if (*(int*)a > *(int*)b)return -1;
    else return 1;
}

int main()
{
    char C;scanf("%c\n",&C);
    int num[100];
    for (int i=0;i<100;i++)num[i]=-1;
    int n=0;
    while (~scanf("%d",&num[n++]));
    n--;

    if(C=='A')
        qsort(num,n,sizeof(int),cmpA);
    else if(C=='D')
        qsort(num,n,sizeof(int),cmpD);
    else    return 0;

    for (int i=0;i<n;i++)
    {
        if(i==0 || i!=0 && num[i]!=num[i-1])printf("%d",num[i]);
        if (i==n-1)printf("\n");
        else if (i==0 || i!=0 && num[i]!=num[i-1]) printf(" ");
    }
    return 0;
}
