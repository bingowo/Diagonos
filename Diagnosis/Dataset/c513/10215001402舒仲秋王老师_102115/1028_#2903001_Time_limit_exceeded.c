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
    while(1)
    {
        mid=getchar();
        if(mid!=' '&&mid!='\n')
        {
            num[i]=num[i]*10+c-'0';
        }
        else if(mid==' '||mid=='\n') i++;
        else if(mid==EOF) break;
    }
    flag=i;
    qsort(num,flag+1,sizeof(num[0]),cmp);
    if(c=='A')
    {
        printf("%d ",num[0]);
        for(i=1;i<=flag;i++)
            if(num[i]!=num[i-1]) printf("%d ",num[i]);
    }
    else
    {
        printf("%d ",num[flag]);
        for(i=flag-1;i>=0;i--)
            if(num[i]!=num[i+1]) printf("%d ",num[i]);
    }
    return 0;
}

