#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[100];
    scanf("%s",a);
    int len=strlen(a);
    int temp=1,ans=1;
    for(int i=0;i<len-1;i++)
    {
        if(a[i]!=a[i+1])
            temp++;
        else
        {
            ans=temp>ans?temp:ans;
            temp=1;
        }
    }
    printf("%d",ans);
    return 0;
}
