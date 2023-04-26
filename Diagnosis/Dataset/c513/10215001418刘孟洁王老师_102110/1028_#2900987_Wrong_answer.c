#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int compare1(const void*a,const void*b)
{
    int c=*(int*)a;
    int d=*(int*)b;
    if(c<d)return -1;
    else return 1;
}

int compare2(const void*a,const void*b)
{
    int c=*(int*)a;
    int d=*(int*)b;
    if(c<d)return 1;
    else return -1;
}

int main()
{
    char s;
    int i=0,j,k,x;
    int t[101],turn[101];
    scanf("%c",&s);
    while(scanf("%d",&t[i])!=EOF)i++;
    turn[0]=t[0];
    for(j=1,x=1;j<i;x++,j++)
    {
        k=0;
        while(k<=x-1)
        {
            if(t[j]!=turn[k])k++;
            else break;
        }
        if(k==x)turn[x]=t[j];
    }
    switch(s)
    {
        case 'A':qsort(turn,x,sizeof(int),compare1);break;
        case 'D':qsort(turn,x,sizeof(int),compare2);break;
    }
    for(i=0;i<x;i++)printf("%d ",turn[i]);
    return 0;
}
