#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[51];
    int a[50];
    int i;
    for(i=0;i<50;i++)
        a[i]=1;
    scanf("%s",s);
    int j,l,k,n=0;
    for(k=0;s[k];k=j,n++)
    {
        for(i=k,j=i+1;s[i]!=s[j];i++,j++)
            a[n]=a[n]+1;
    }
    l=0;
    l=(a[0]>a[1])?a[0]:a[1];
    for(i=2;i<50;i++)
    {
        l=(l>a[i])?l:a[i];
    }
    printf("%d",l);
}