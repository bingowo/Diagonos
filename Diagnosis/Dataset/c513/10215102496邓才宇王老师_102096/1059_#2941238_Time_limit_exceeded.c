#include <stdio.h>
#include <stdlib.h>
int min(int *p)
{
    int num=0;
    while(*++p)
    {
        if(*p<=*(p+1)&&*p<=*(p-1))
            return *p;
    }
}
int main()
{
    int n,s;
    scanf("%d %d",&n,&s);
    int a[2000];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    while(1)
    {
        int q=min(a);
        int num=0;
        for(int j=0;a[j];j++)
        {
            if(a[j]==q) num++;
        }
        if(num<s)
        {
            s=s-num;
            for(int j=0;a[j];j++)
            {
                if(a[j]==q) a[j]=a[j]+1;
            }
        }
        else
        {
            if(num==s)
            {
                printf("%d",q+1);
                break;
            }
            else
            {
                printf("%d+%d/%d",q,s,num);
                break;
            }
        }
    }
}
