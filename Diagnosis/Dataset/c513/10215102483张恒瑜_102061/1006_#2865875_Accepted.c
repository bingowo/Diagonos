#include<stdio.h>
#include<string.h>

int main()
{
    int T,t=0;
    scanf("%d",&T);
    while (T--)
    {
        char input[10000]={'\0'};
        scanf("%s",&input);
        int i;
        long long res=0,max=1;
        for(i=1;i<strlen(input);i++)
        {
            max*=3;
        }

        for(i=0;i<strlen(input);i++)
        {
            switch (input[i])
            {
            case '-':
                res+=-max;
                break;
            case '1':
                res+=max;
                break;
            default:
                break;
            }
            max/=3;
        }
        printf("case #%d:\n%lld\n",t,res);
        t++;
    }
    return 0;
}
