#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0,k=0;t<T;t++)
    {
        char a[100];
        int sum=0;
        for(int i=0;a[i]!='\n';i++)scanf("%c",&a[i]);
        for(int i=0;i<strlen(a);i++)
    {
        if(a[i]=='1')sum=sum*3+1;
        if(a[i]=='0')sum=sum*3;
        if(a[i]=='-')sum=sum*3-1;
    }
        printf("case #%d:\n",k);
        printf("%d",sum);
        k++;
    }
    return 0;
}
