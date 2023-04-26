#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 100

 int method(char s[])
{
    int sum = 0;
    for(int i = 0;i < strlen(s);i++)
    {
        if(s[i] == '1')
        {
            sum = sum*3 + 1;
        }
        else if(s[i] == '0')
        {
            sum = sum*3;
        }
        else if(s[i] == '-')
        {
            sum = sum*3 - 1;
        }
    }
    return sum;

}

int main()
{
    int n;
    char s[N][N];
    scanf("%d",&n);

    for(int i = 0;i < n;i++)
    {
        scanf("%s",s[i]);
    }

        for(int i = 0;i < n;i++)
    {
        printf("case #%d:\n%d\n",i,method(s[i]));
    }
    return 0;
}
