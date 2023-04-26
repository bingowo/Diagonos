#include <stdio.h>
#include <stdlib.h>
int min(int *p)
{
    int num=*p;
    while(*++p)
    {
        if(num>*p) num=*p;
    }
    return num;
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
    int q=min(a);
    while(1)
    {
         printf("%d\n",q);
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
            q++;
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
