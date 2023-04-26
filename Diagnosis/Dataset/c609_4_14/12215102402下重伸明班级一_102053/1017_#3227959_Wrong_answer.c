#include<stdio.h>
int main()
{
    char s=getchar();
    int i=0,n,a[101],b[1001]={0};
    while(scanf("%d",&n)==1)
    {
        b[n]=1;
        i++;
    }
    for(int j=0;j<1001;j++)
    {
        if(b[j]==1)
        {
            a[i]=j;
            i++;
        }
    }
    for(int k=0;k<i;k++)
    {
        printf("%d ",a[k]);
    }
}