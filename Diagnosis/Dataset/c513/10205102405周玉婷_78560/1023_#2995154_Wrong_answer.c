#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char s[31];
    int num;
} str;

int cmp(const void *a,const void *b)
{
    str pa=*(str*)a;
    str pb=*(str*)b;
    if(pa.num==pb.num)
    return strcmp(pa.s,pb.s);
    else 
    return pa.num>pb.num?1:-1;
}

int main()
{
    str arr[100];
    int i=0,n=0;
    while(~scanf("%s",arr[i].s))
    {i+=1;
    n++;}
    char number[9];
    for(int i=0; i<n; i++)
    {
        int k=0;
        for(int j=0; arr[i].s[j]; j++)
        {
           if(arr[i].s[j]<58) 
           number[k++]=arr[i].s[j];
        }
        if(k!=0)
        arr[i].num=atoi(number);
        else 
        arr[i].num=0;
    }

    qsort(arr,n,sizeof(str),cmp);
    for(int i=0; i<n; i++)
    {
        printf("%s%c",arr[i].s,i==n-1?'\n':' ');
    }
    return 0;

}