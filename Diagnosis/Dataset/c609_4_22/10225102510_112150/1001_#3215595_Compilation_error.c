#include <stdio.h>
#include <stdlib.h>
#define N 10000
int main()
{
    int s[N],t[N];
    char a[N],b[N];
    int i=0,j=0;
    scanf("%d",&T);
    while(i<T)
    {
        scanf("%d",&s[i]);
        scanf("%d",&t[i]);
        i++;
    }
    for(i=0;i<T;i++)
    {
        if(s[i]<0)
        {
            a[j]='-';
            j++;
            s[i]=-s[i];
        }
        for(;s[i]%t[i]!=0;j++)
        {
            if(s[i]%t[i]<10)
            a[j]=s[i]%t[i];
            else a[j]='A'+s[i]%t[i]-10;
        }
        j=0;
        printf("%s\n",a);
    }
    return 0;
}
