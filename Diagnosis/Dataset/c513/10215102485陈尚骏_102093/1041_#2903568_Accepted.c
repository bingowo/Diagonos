#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    char a[51];
    int i=1,j=0,k=0;
    scanf("%s",a);
    for(;j<strlen(a);j++)
    {
        if(a[j]==a[j+1]||a[j+1]=='\0')
        {
            if(k<i)
            k=i;
    i=1;
    }
    else i++;
    }
    printf("%d\n",k);
    return 0;
}
