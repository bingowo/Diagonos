#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b)
{
    int d1,d2;
    d1=*((int*)a),d2=*((int*)b);
    return d1-d2;
}

int main()
{
    char c;
    int num[500],i,flag;
    scanf("%c",&c);
    for(i=0;scanf("%d",&num[i]);i++);
    flag=i;
    qsort(num,i,sizeof(num[0]),cmp);
    if(c=='A')
    {
        printf("%d",num[0]);
        for(i=1;i<flag;i++)
            if(num[i]!=num[i-1]) printf("%d",num[i]);
    }
    else
    {
        printf("%d",num[flag-1]);
        for(i=flag-2;i>=0;i--)
            if(num[i]!=num[i+1]) printf("%d",num[i]);
    }
    return 0;
}
