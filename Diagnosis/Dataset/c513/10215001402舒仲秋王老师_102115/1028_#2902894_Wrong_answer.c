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
    char c,mid[500];
    int num[500],i,flag,j;
    for(i=0;i<500;i++) num[i]=0;
    scanf("%c\n",&c);
    gets(mid);
    for(i=0,j=0;i<strlen(mid);i++)
    {
        if(mid[i]==' ') {j++;continue;}
        num[j]=num[j]*10+mid[i]-'0';
    }
    flag=j;
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


