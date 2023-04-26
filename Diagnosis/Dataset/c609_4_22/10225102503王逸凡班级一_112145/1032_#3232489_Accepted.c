#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[51];
    scanf("%s",a);
    int len = strlen(a);
    int cnt=1,sum=1;
    for (int i=1;i<len;i++){
        if(a[i]==a[i-1])
        {
            if (cnt>sum)
            {
                sum=cnt;
                cnt=1;
            }
            else
            {
                cnt=1;
            }
        }
        else
        {
            cnt++;
        }
    }
    if (cnt > sum)
    {
        sum=cnt;
    }
    printf("%d",sum);
    return 0;
}
