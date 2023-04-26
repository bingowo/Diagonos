#include<stdio.h>
#include<string.h>

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    while (T--)
    {
        char input[150]={'\0'};
        int i=0;
        char c;
        while((c=getchar())!=EOF && c!='\n')
        {
            input[i++]=c;
        }
        int sum=0;
        for(i=0;i<strlen(input);i++)
        {
            int j;
            for(j=0;j<=8;j++)
            {
                if(input[i]<<j>>7==1) sum++;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}