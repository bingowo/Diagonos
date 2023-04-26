#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    int T;
    char str[100];
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int sum=0;
        scanf("%s",str);
        printf("case #%d:\n",i);
        for(int j=0;j<strlen(str);j++)
        {
                if(str[j]=='1')
                    sum=sum*3+1;
                else if(str[j]=='0')
                    sum=sum*3;
                else if(str[j]=='-')
                    sum=sum*3-1;
        }
        printf("%d\n",sum);
    }
    return 0;
}
