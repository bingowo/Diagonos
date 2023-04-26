#include <stdio.h>
#include <stdlib.h>

int main()
{
    char x;
    scanf("%c",&x);
    int a[1002];
    int c[1002];
    for(int i=0;i<=1001;i++)
        a[i]=0;
    int index;
    while(scanf("%d",&index)!=-1)
        a[index]=1;
    int j=0;
    int m=0;
    if (x=='A')
        for(;j<=1001;j++)
    {
        if(a[j]==1)
            {c[m]=j;m++;}
    }
    else
        for(j=1001;j>0;j--,m++)
    {
        if(a[j]==1)
            {c[m]=j;m++;}
    }
    for(int n=0;n<m-1;n++)
        printf("%d ",c[n]);
    printf("%d",c[m-1]);
    return 0;
}
