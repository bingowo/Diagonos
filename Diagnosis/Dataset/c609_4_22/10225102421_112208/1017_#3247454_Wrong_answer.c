#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void*a,const*b)
{
    int i=*(int*)a,j=*(int*)b;
    return i-j;
}

int main()
{
    char c;
    scanf("%s",&c);
    int str[100],n;
    n=0;
    while (scanf("%d",&str[n])!=EOF)
        n++;

    qsort(str,n,sizeof(str[0]),cmp);
    for (int x=0;x<n-1;x++)
    {
        int y=1;
        while (y<=n-1)
        {
            if (str[y]==str[x])
            {
                for (int z=y;z<n-1;z++)
                    str[z]=str[z+1];
                n=n-1;
            }
            y=y+1;
        }
    }
    if (n==1)
        printf("%d",str[0]);
    else if(c=='A')
    {
        for (int i=0;i<n;i++)
            printf("%d ",str[i]);
    }
    else
    {
        for (int i=n;i>0;i--)
            printf("%d ",str[i]);
    }
    return 0;
}
