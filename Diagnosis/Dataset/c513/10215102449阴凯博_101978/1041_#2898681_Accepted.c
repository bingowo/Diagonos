#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char s[55]={0};
    scanf("%s",s);
    int i,j,cnt=1,flag=0;
    for (i=1;i<strlen(s);i++)
    {
        if (s[i]!=s[i-1])
        {
            cnt++;
        }
        else
        {
            flag=(flag<cnt)?cnt:flag;
            cnt=1;
        }
    }
    flag=(flag<cnt)?cnt:flag;
    printf("%d\n",flag);

}
