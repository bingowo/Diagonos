#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int cmp(const void* a,const void* b)
{
    int d1,d2;
    d1=*((int*)a),d2=*((int*)b);
    return d1-d2;
}

int main()
{
    char c,mid;
    int num[500],i=0,flag;
    for(i=0;i<500;i++) num[i]=0;
    scanf("%c\n",&c);i=0;
    while((mid=getchar())!=EOF)
    {
        if(mid!=' '&&mid!='\n')
        {
            num[i]=num[i]*10+mid-'0';
        }
        else if(mid==' '||mid=='\n') i++;
    }
    flag=i;
    qsort(num,flag,sizeof(num[0]),cmp);
    if(c=='A')
    {
        if(num[0]!=0) printf("%d ",num[0]);
        for(i=1;i<flag;i++)
            if((num[i]!=num[i-1])&&num[i]!=0) printf("%d ",num[i]);
    }
    else
    {
        printf("%d ",num[flag-1]);
        for(i=flag-2;i>=0;i--)
            if((num[i]!=num[i+1])&&num[i]!=0) printf("%d ",num[i]);
    }
    return 0;
}

