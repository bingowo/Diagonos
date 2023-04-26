#include <stdio.h>
#include <string.h>

int main()
{
    int k=0,T;
    int sum=0;
    scanf("%d",&T);
    while(T--)
    {
        char str[101];
        scanf("%s",str);
        for(int i=0;i<strlen(str);i++)
        {
            sum=sum*3+f(str[i]);            
        }
        printf("case #%d:\n",k);
        printf("%d",sum);
        k++;
    }
    return 0;
}

int f(char s)
{
    if(s=='0')return 0;
    if(s=='1')return 1;
    if(s=='-')return -1;
}